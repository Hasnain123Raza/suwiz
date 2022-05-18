#include "constraints.h"

int16_t *suwiz_constraints_create() {
    int16_t *constraints = (int16_t *)malloc(sizeof(int16_t) * SUWIZ_BOARD_SIZE);
    if (constraints == NULL) {
        return NULL;
    }

    for (int counter = 0; counter < SUWIZ_BOARD_SIZE; counter++) {
        constraints[counter] = SUWIZ_CONSTRAINTS_CHOICE_ALL;
    }

    return constraints;
}

int16_t *suwiz_constraints_clone(int16_t *constraints) {
    if (constraints == NULL) {
        return NULL;
    }

    int16_t *new_constraints = (int16_t *)malloc(sizeof(int16_t) * SUWIZ_BOARD_SIZE);
    if (new_constraints == NULL) {
        return NULL;
    }

    memcpy(new_constraints, constraints, sizeof(int16_t) * SUWIZ_BOARD_SIZE);

    return new_constraints;
}

void suwiz_constraints_free(int16_t *constraints) {
    if (constraints != NULL) {
        free(constraints);
    }
}



enum SuwizConstraintsStatus suwiz_constraints_status(int16_t *constraints) {
    int board_unsolved = 0;

    for (int counter = 0; counter < SUWIZ_BOARD_SIZE; counter++) {
        int16_t cell = constraints[counter];

        if (cell == SUWIZ_CONSTRAINTS_CHOICE_NONE) {
            return SUWIZ_CONSTRAINTS_STATUS_INVALID;
        }

        if (!SUWIZ_CONSTRAINTS_IS_VALUE(cell)) {
            board_unsolved = 1;
        }
    }

    if (board_unsolved) {
        return SUWIZ_CONSTRAINTS_STATUS_UNSOLVED;
    }

    return SUWIZ_CONSTRAINTS_STATUS_SOLVED;
}

void suwiz_constraints_solve(int16_t *constraints, int index, int choice) {
    constraints[index] = choice;
    choice = SUWIZ_CONSTRAINTS_INT_TO_CHOICE(choice);

    int row = SUWIZ_BOARD_INDEX_TO_ROW(index);
    int column = SUWIZ_BOARD_INDEX_TO_COLUMN(index);
    int box = SUWIZ_BOARD_INDEX_TO_BOX(index);

    for (int counter = 0; counter < SUWIZ_BOARD_ROWS; counter++) {
        int row_index = SUWIZ_BOARD_INDEX_ROW(row, counter);
        if (!SUWIZ_CONSTRAINTS_IS_VALUE(constraints[row_index])) {
            constraints[row_index] = SUWIZ_CONSTRAINTS_REMOVE_CHOICE(constraints[row_index], choice);
        }

        int column_index = SUWIZ_BOARD_INDEX_COLUMN(column, counter);
        if (!SUWIZ_CONSTRAINTS_IS_VALUE(constraints[column_index])) {
            constraints[column_index] = SUWIZ_CONSTRAINTS_REMOVE_CHOICE(constraints[column_index], choice);
        }

        int box_index = SUWIZ_BOARD_INDEX_BOX(box, counter);
        if (!SUWIZ_CONSTRAINTS_IS_VALUE(constraints[box_index])) {
            constraints[box_index] = SUWIZ_CONSTRAINTS_REMOVE_CHOICE(constraints[box_index], choice);
        }
    }
}