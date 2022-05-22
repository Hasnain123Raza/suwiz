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



#define ROW_FLAG 0b1
#define SET_ROW_FLAG(flag) ((flag) |= ROW_FLAG)
#define GET_ROW_FLAG(flag) ((flag) & ROW_FLAG)
#define COLUMN_FLAG 0b10
#define SET_COLUMN_FLAG(flag) ((flag) |= COLUMN_FLAG)
#define GET_COLUMN_FLAG(flag) ((flag) & COLUMN_FLAG)
#define BOX_FLAG 0b100
#define SET_BOX_FLAG(flag) ((flag) |= BOX_FLAG)
#define GET_BOX_FLAG(flag) ((flag) & BOX_FLAG)
enum SuwizConstraintsStatus suwiz_constraints_status(int16_t *constraints) {
    char unique_value_flags[9][9] = {0};
    int board_unsolved = 0;

    for (int counter = 0; counter < SUWIZ_BOARD_SIZE; counter++) {
        int16_t cell = constraints[counter];

        if (cell == SUWIZ_CONSTRAINTS_CHOICE_NONE) {
            return SUWIZ_CONSTRAINTS_STATUS_INVALID;
        }

        if (SUWIZ_CONSTRAINTS_IS_VALUE(cell)) {
            continue;
        } else {
            board_unsolved = 1;
        }

        if (SUWIZ_CONSTRAINTS_CHOICE_COUNT(cell) > 1) {
            continue;
        }

        int value;
        switch(cell) {
            case SUWIZ_CONSTRAINTS_CHOICE_ONE: value = 1; break;
            case SUWIZ_CONSTRAINTS_CHOICE_TWO: value = 2; break;
            case SUWIZ_CONSTRAINTS_CHOICE_THREE: value = 3; break;
            case SUWIZ_CONSTRAINTS_CHOICE_FOUR: value = 4; break;
            case SUWIZ_CONSTRAINTS_CHOICE_FIVE: value = 5; break;
            case SUWIZ_CONSTRAINTS_CHOICE_SIX: value = 6; break;
            case SUWIZ_CONSTRAINTS_CHOICE_SEVEN: value = 7; break;
            case SUWIZ_CONSTRAINTS_CHOICE_EIGHT: value = 8; break;
            case SUWIZ_CONSTRAINTS_CHOICE_NINE: value = 9; break;
            default: return;
        }
        int value_index = value - 1;
        int row = SUWIZ_BOARD_INDEX_TO_ROW(counter);
        int column = SUWIZ_BOARD_INDEX_TO_COLUMN(counter);
        int box = SUWIZ_BOARD_INDEX_TO_BOX(counter);

        if (GET_ROW_FLAG(unique_value_flags[row][value_index])) {
            return SUWIZ_CONSTRAINTS_STATUS_INVALID;
        }
        SET_ROW_FLAG(unique_value_flags[row][value_index]);

        if (GET_COLUMN_FLAG(unique_value_flags[column][value_index])) {
            return SUWIZ_CONSTRAINTS_STATUS_INVALID;
        }
        SET_COLUMN_FLAG(unique_value_flags[column][value_index]);

        if (GET_BOX_FLAG(unique_value_flags[box][value_index])) {
            return SUWIZ_CONSTRAINTS_STATUS_INVALID;
        }
        SET_BOX_FLAG(unique_value_flags[box][value_index]);
    }

    if (board_unsolved) {
        return SUWIZ_CONSTRAINTS_STATUS_UNSOLVED;
    }

    return SUWIZ_CONSTRAINTS_STATUS_SOLVED;
}

void suwiz_constraints_solve(int16_t *constraints, int index, int16_t choice) {
    int value;
    switch(choice) {
        case SUWIZ_CONSTRAINTS_CHOICE_ONE: value = 1; break;
        case SUWIZ_CONSTRAINTS_CHOICE_TWO: value = 2; break;
        case SUWIZ_CONSTRAINTS_CHOICE_THREE: value = 3; break;
        case SUWIZ_CONSTRAINTS_CHOICE_FOUR: value = 4; break;
        case SUWIZ_CONSTRAINTS_CHOICE_FIVE: value = 5; break;
        case SUWIZ_CONSTRAINTS_CHOICE_SIX: value = 6; break;
        case SUWIZ_CONSTRAINTS_CHOICE_SEVEN: value = 7; break;
        case SUWIZ_CONSTRAINTS_CHOICE_EIGHT: value = 8; break;
        case SUWIZ_CONSTRAINTS_CHOICE_NINE: value = 9; break;
        default: return;
    }
    constraints[index] = value;

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

int suwiz_constraints_solve_singles(int16_t *constraints) {
    for (int cell_index = 0; cell_index < SUWIZ_BOARD_SIZE; cell_index++) {
        int16_t cell = constraints[cell_index];

        if (SUWIZ_CONSTRAINTS_IS_VALUE(cell)) {
            continue;
        }

        if (SUWIZ_CONSTRAINTS_CHOICE_COUNT(cell) != 1) {
            continue;
        }

        suwiz_constraints_solve(constraints, cell_index, cell);
        if (suwiz_constraints_status(constraints) == SUWIZ_CONSTRAINTS_STATUS_INVALID) {
            return 0;
        }

        cell_index = 0;
    }

    return 1;
}