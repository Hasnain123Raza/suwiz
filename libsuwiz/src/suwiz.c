#include "suwiz.h"

int8_t *suwiz_board_create(char *board_str) {
    int8_t *board = malloc(sizeof(int8_t) * SUWIZ_BOARD_SIZE);
    if (board == NULL) {
        return NULL;
    }

    if (board_str == NULL) {
        memset(board, INT8_C(0), sizeof(int8_t) * SUWIZ_BOARD_SIZE);
        return board;
    }

    for (int counter = 0; counter < SUWIZ_BOARD_SIZE; counter++) {
        char character = '.';

        if (*board_str != '\0') {
            character = *(board_str++);
            if (character == '0') {
                character = '.';
            }
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
    if (board != NULL) {
        free(board);
    }
}



void suwiz_board_print(int8_t *board, char *board_str) {
    if (board == NULL || board_str == NULL) {
        return;
    }

    for (int counter = 0; counter < SUWIZ_BOARD_SIZE; counter++) {
        if (board[counter] == INT8_C(0)) {
            *(board_str++) = '.';
        } else {
            *(board_str++) = board[counter] + '0';
        }
    }

    *(board_str++) = '\0';
}

enum SuwizBoardStatus suwiz_board_status(int8_t *board) {
    return SUWIZ_BOARD_STATUS_INVALID;
}