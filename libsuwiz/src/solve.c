#include "solve.h"

int16_t *suwiz_board_to_constraints(int8_t *board) {
    if (board == NULL) {
        return NULL;
    }

    enum SuwizBoardStatus status = suwiz_board_status(board);
    if (status == SUWIZ_BOARD_STATUS_INVALID) {
        return NULL;
    }

    int16_t *constraints = suwiz_constraints_create();
    if (status == SUWIZ_BOARD_STATUS_SOLVED) {
        for (int counter = 0; counter < SUWIZ_BOARD_SIZE; counter++) {
            constraints[counter] = INT16_C(board[counter]);
        }
        return constraints;
    }

    for (int counter = 0; counter < SUWIZ_BOARD_SIZE; counter++) {
        if (board[counter] != 0) {
            suwiz_constraints_solve(constraints, counter, board[counter]);
        }
    }

    return constraints;
}

int8_t *suwiz_constraints_to_board(int16_t *constraints) {
    if (constraints == NULL) {
        return NULL;
    }

    int8_t *board = suwiz_board_create(NULL);
    for (int counter = 0; counter < SUWIZ_BOARD_SIZE; counter++) {
        if (SUWIZ_CONSTRAINTS_IS_VALUE(constraints[counter])) {
            board[counter] = INT8_C(constraints[counter]);
        }
    }

    return board;
}



int8_t **suwiz_board_solve(int8_t *board, int max_solutions, int *solutions_found) {
    return NULL;
}