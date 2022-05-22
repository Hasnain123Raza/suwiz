#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "constraints.h"
#include "convert.h"
#include "suwiz.h"

struct recurse_data_t {
    int8_t **solutions_array;
    int solutions_array_capacity;
    int max_solutions;
    int solutions_found;
};

static int recurse(struct recurse_data_t *data, int16_t *constraints);
static struct recurse_data_t *recurse_data_create(int max_solutions);
static void recurse_data_free(struct recurse_data_t *data);
static int recurse_data_grow(struct recurse_data_t *data);
static int recurse_data_push(struct recurse_data_t *data, int16_t *constraints);



int8_t **suwiz_board_solve_recursive(int8_t *board, int max_solutions, int *solutions_found) {
    if (board == NULL) {
        return NULL;
    }

    int status = suwiz_board_status(board);
    if (status == SUWIZ_BOARD_STATUS_INVALID) {
        return NULL;
    } else if (status == SUWIZ_BOARD_STATUS_SOLVED) {
        int8_t **solutions_array = (int8_t **)malloc(sizeof(int8_t *) * 1);
        if (solutions_array == NULL) {
            return NULL;
        }

        solutions_array[0] = (int8_t *)malloc(sizeof(int8_t) * SUWIZ_BOARD_SIZE);
        if (solutions_array[0] == NULL) {
            free(solutions_array);
            return NULL;
        }

        memcpy(solutions_array[0], board, sizeof(int8_t) * SUWIZ_BOARD_SIZE);
        *solutions_found = 1;
        return solutions_array;
    }

    struct recurse_data_t *data = recurse_data_create(max_solutions);
    if (data == NULL) {
        return NULL;
    }

    int16_t *constraints = suwiz_board_to_constraints(board);
    if (constraints == NULL) {
        free(data->solutions_array);
        free(data);
        return NULL;
    }
    suwiz_constraints_solve_singles(constraints);

    printf("START\n");
    int success = recurse(data, constraints);
    int8_t **solutions = data->solutions_array;
    *solutions_found = data->solutions_found;

    free(constraints);
    if (!success) {
        recurse_data_free(data);
        return NULL;
    }
    free(data);
    
    return solutions;
}



static int recurse(struct recurse_data_t *data, int16_t *constraints) {
    static int count = 0;
    count++;
    int8_t *board = suwiz_constraints_to_board(constraints);
    char board_str[SUWIZ_BOARD_SIZE + 1];
    suwiz_board_print(board, board_str);
    printf("%d: %s\n", count, board_str);
    suwiz_board_free(board);

    int status = suwiz_constraints_status(constraints);

    if (status == SUWIZ_CONSTRAINTS_STATUS_SOLVED) {
        int push_success = recurse_data_push(data, constraints);
        if (push_success) {
            return 1;
        } else {
            return 0;
        }
    }

    if (status == SUWIZ_CONSTRAINTS_STATUS_INVALID) {
        return 1;
    }

    for (int cell_index = 0; cell_index < SUWIZ_BOARD_SIZE; cell_index++) {
        int16_t cell = constraints[cell_index];

        if (SUWIZ_CONSTRAINTS_IS_VALUE(cell)) {
            continue;
        }

        for (int choice_index = 1; choice_index <= SUWIZ_BOARD_CHOICES; choice_index++) {
            int16_t choice = SUWIZ_CONSTRAINTS_INT_TO_CHOICE(choice_index);
            if (!SUWIZ_CONSTRAINTS_HAS_CHOICE(cell, choice)) {
                continue;
            }

            int16_t *new_constraints = suwiz_constraints_clone(constraints);
            if (new_constraints == NULL) {
                return 0;
            }
            suwiz_constraints_solve(new_constraints, cell_index, choice);
            if (!suwiz_constraints_solve_singles(new_constraints)) {
                free(new_constraints);
                continue;
            }

            int recurse_success = recurse(data, new_constraints);
            suwiz_constraints_free(new_constraints);

            if (!recurse_success) {
                return 0;
            }

            if ((data->max_solutions != -1) && (data->solutions_found >= data->max_solutions)) {
                return 1;
            }
        }
    }

    
    return 1;
}

static struct recurse_data_t *recurse_data_create(int max_solutions) {
    struct recurse_data_t *data = (struct recurse_data_t *)malloc(sizeof(struct recurse_data_t));
    if (data == NULL) {
        return NULL;
    }

    int8_t **solutions_array = (int8_t **)malloc(sizeof(int8_t *));
    if (solutions_array == NULL) {
        free(data);
        return NULL;
    }

    data->solutions_array = solutions_array;
    data->solutions_array_capacity = 1;
    data->max_solutions = max_solutions;
    data->solutions_found = 0;

    return data;
}

static void recurse_data_free(struct recurse_data_t *data) {
    for (int counter = 0; counter < data->solutions_found; counter++) {
        free(data->solutions_array[counter]);
    }
    free(data->solutions_array);
    free(data);
}

static int recurse_data_grow(struct recurse_data_t *data) {
    int8_t **solutions_array = (int8_t **)realloc(data->solutions_array, sizeof(int8_t *) * data->solutions_array_capacity * 2);
    if (solutions_array == NULL) {
        return 0;
    }

    data->solutions_array = solutions_array;
    data->solutions_array_capacity *= 2;

    return 1;
}

static int recurse_data_push(struct recurse_data_t *data, int16_t *constraints) {
    int8_t *solution = suwiz_constraints_to_board(constraints);
    enum SuwizBoardStatus status = suwiz_board_status(solution);
    if (status == SUWIZ_BOARD_STATUS_INVALID) {
        suwiz_board_free(solution);
        return 1;
    }

    for (int counter = 0; counter < data->solutions_found; counter++) {
        if (memcmp(data->solutions_array[counter], solution, SUWIZ_BOARD_SIZE) == 0) {
            suwiz_board_free(solution);
            return 1;
        }
    }

    if (data->solutions_found == data->solutions_array_capacity) {
        if (!recurse_data_grow(data)) {
            suwiz_board_free(solution);
            return 0;
        }
    }

    data->solutions_array[data->solutions_found] = solution;
    data->solutions_found++;

    return 1;
}