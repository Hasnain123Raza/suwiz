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

#define ROW_FLAG 0b1
#define SET_ROW_FLAG(flag) ((flag) |= ROW_FLAG)
#define GET_ROW_FLAG(flag) ((flag) & ROW_FLAG)
#define COLUMN_FLAG 0b10
#define SET_COLUMN_FLAG(flag) ((flag) |= COLUMN_FLAG)
#define GET_COLUMN_FLAG(flag) ((flag) & COLUMN_FLAG)
#define BOX_FLAG 0b100
#define SET_BOX_FLAG(flag) ((flag) |= BOX_FLAG)
#define GET_BOX_FLAG(flag) ((flag) & BOX_FLAG)
enum SuwizBoardStatus suwiz_board_status(int8_t *board) {
    if (board == NULL) {
        return SUWIZ_BOARD_STATUS_INVALID;
    }

    char unique_value_flags[9][9] = {0};
    char board_unsolved = 0;

    for (int counter = 0; counter < SUWIZ_BOARD_SIZE; counter++) {
        int8_t value = board[counter];

        if (value == INT8_C(0)) {
            board_unsolved = 1;
            continue;
        }

        int value_index = value - 1;
        int row = SUWIZ_BOARD_INDEX_TO_ROW(counter);
        int column = SUWIZ_BOARD_INDEX_TO_COLUMN(counter);
        int box = SUWIZ_BOARD_INDEX_TO_BOX(counter);

        if (GET_ROW_FLAG(unique_value_flags[row][value_index])) {
            return SUWIZ_BOARD_STATUS_INVALID;
        }
        SET_ROW_FLAG(unique_value_flags[row][value_index]);

        if (GET_COLUMN_FLAG(unique_value_flags[column][value_index])) {
            return SUWIZ_BOARD_STATUS_INVALID;
        }
        SET_COLUMN_FLAG(unique_value_flags[column][value_index]);

        if (GET_BOX_FLAG(unique_value_flags[box][value_index])) {
            return SUWIZ_BOARD_STATUS_INVALID;
        }
        SET_BOX_FLAG(unique_value_flags[box][value_index]);
    }

    if (board_unsolved) {
        return SUWIZ_BOARD_STATUS_UNSOLVED;
    }

    return SUWIZ_BOARD_STATUS_SOLVED;
}