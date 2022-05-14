#include "suwiz.h"

int8_t *suwiz_board_create(char *board_str) {
    int8_t *board = malloc(sizeof(int8_t) * SUWIZ_BOARD_SIZE);
    if (board == NULL) {
        return NULL;
    }

    for (int counter = 0; counter < SUWIZ_BOARD_SIZE; counter++) {
        char character = '.';
        if ((board_str != NULL) && (*board_str != '\0')) {
            character = *(board_str++);
        }

        if (character == '.') {
            board[counter] = INT8_C(0);
        } else if (character >= '0' && character <= '9') {
            board[counter] = INT8_C(character - '0');
        } else {
            free(board);
            return NULL;
        }
    }

    return board;
}

void suwiz_board_free(int8_t *board) {
    free(board);
}



void suwiz_board_print(int8_t *board, char *board_str) {

}

enum SuwizBoardStatus suwiz_board_status(int8_t *board) {
    return SUWIZ_BOARD_STATUS_INVALID;
}