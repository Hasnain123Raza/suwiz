#include "test_suwiz.h"

static int8_t sample_board[81] = {
    0,  1,  2,      3,  4,  5,      6,  7,  8,
    9,  10, 11,     12, 13, 14,     15, 16, 17,
    18, 19, 20,     21, 22, 23,     24, 25, 26,

    27, 28, 29,     30, 31, 32,     33, 34, 35,
    36, 37, 38,     39, 40, 41,     42, 43, 44,
    45, 46, 47,     48, 49, 50,     51, 52, 53,

    54, 55, 56,     57, 58, 59,     60, 61, 62,
    63, 64, 65,     66, 67, 68,     69, 70, 71,
    72, 73, 74,     75, 76, 77,     78, 79, 80
};

int init_suite_suwiz(void) {
    return 0;
}

int clean_suite_suwiz(void) {
    return 0;
}

CU_ErrorCode prepare_suite_suwiz(void) {
    CU_pSuite suite_suwiz = CU_add_suite("suwiz", init_suite_suwiz, clean_suite_suwiz);
    if (suite_suwiz == NULL) {
        return CU_get_error();
    }

    if ((CU_add_test(suite_suwiz, "test_suwiz_board_index_row", test_suwiz_board_index_row) == NULL) ||
        (CU_add_test(suite_suwiz, "test_suwiz_board_index_column", test_suwiz_board_index_column) == NULL) ||
        (CU_add_test(suite_suwiz, "test_suwiz_board_index_box", test_suwiz_board_index_box) == NULL) ||
        (CU_add_test(suite_suwiz, "test_suwiz_board_create", test_suwiz_board_create) == NULL) ||
        (CU_add_test(suite_suwiz, "test_suwiz_board_free", test_suwiz_board_free) == NULL) ||
        (CU_add_test(suite_suwiz, "test_suwiz_board_print", test_suwiz_board_print) == NULL) ||
        (CU_add_test(suite_suwiz, "test_suwiz_board_status", test_suwiz_board_status) == NULL)) {
        return CU_get_error();
    }

    return CUE_SUCCESS;
}



void test_suwiz_board_index_row(void) {
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(0, 0), 0);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(0, 4), 4);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(0, 8), 8);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(1, 0), 9);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(1, 4), 13);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(1, 8), 17);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(2, 0), 18);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(2, 4), 22);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(2, 8), 26);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(3, 0), 27);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(3, 4), 31);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(3, 8), 35);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(4, 0), 36);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(4, 4), 40);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(4, 8), 44);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(5, 0), 45);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(5, 4), 49);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(5, 8), 53);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(6, 0), 54);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(6, 4), 58);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(6, 8), 62);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(7, 0), 63);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(7, 4), 67);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(7, 8), 71);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(8, 0), 72);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(8, 4), 76);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_ROW(8, 8), 80);
}

void test_suwiz_board_index_column(void) {
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(0, 0), 0);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(0, 4), 36);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(0, 8), 72);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(1, 0), 1);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(1, 4), 37);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(1, 8), 73);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(2, 0), 2);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(2, 4), 38);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(2, 8), 74);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(3, 0), 3);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(3, 4), 39);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(3, 8), 75);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(4, 0), 4);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(4, 4), 40);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(4, 8), 76);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(5, 0), 5);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(5, 4), 41);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(5, 8), 77);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(6, 0), 6);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(6, 4), 42);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(6, 8), 78);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(7, 0), 7);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(7, 4), 43);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(7, 8), 79);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(8, 0), 8);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(8, 4), 44);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_COLUMN(8, 8), 80);
}

void test_suwiz_board_index_box(void) {
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(0, 0), 0);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(0, 4), 10);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(0, 8), 20);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(1, 0), 3);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(1, 4), 13);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(1, 8), 23);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(2, 0), 6);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(2, 4), 16);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(2, 8), 26);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(3, 0), 27);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(3, 4), 37);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(3, 8), 47);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(4, 0), 30);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(4, 4), 40);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(4, 8), 50);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(5, 0), 33);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(5, 4), 43);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(5, 8), 53);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(6, 0), 54);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(6, 4), 64);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(6, 8), 74);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(7, 0), 57);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(7, 4), 67);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(7, 8), 77);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(8, 0), 60);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(8, 4), 70);
    CU_ASSERT_EQUAL(SUWIZ_BOARD_INDEX_BOX(8, 8), 80);
}

void test_suwiz_board_create(void) {
    int8_t *board = NULL;

    board = suwiz_board_create("123456789000...000a...0");
    CU_ASSERT_PTR_NULL(board);

    board = suwiz_board_create(NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    CU_ASSERT_EQUAL(board[0], INT8_C(0));
    CU_ASSERT_EQUAL(board[80], INT8_C(0));
    suwiz_board_free(board);

    board = suwiz_board_create("");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    CU_ASSERT_EQUAL(board[0], INT8_C(0));
    CU_ASSERT_EQUAL(board[80], INT8_C(0));
    suwiz_board_free(board);

    board = suwiz_board_create("123456789");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    CU_ASSERT_EQUAL(board[0], INT8_C(1));
    CU_ASSERT_EQUAL(board[1], INT8_C(2));
    CU_ASSERT_EQUAL(board[2], INT8_C(3));
    CU_ASSERT_EQUAL(board[3], INT8_C(4));
    CU_ASSERT_EQUAL(board[4], INT8_C(5));
    CU_ASSERT_EQUAL(board[5], INT8_C(6));
    CU_ASSERT_EQUAL(board[6], INT8_C(7));
    CU_ASSERT_EQUAL(board[7], INT8_C(8));
    CU_ASSERT_EQUAL(board[8], INT8_C(9));
    CU_ASSERT_EQUAL(board[9], INT8_C(0));
    CU_ASSERT_EQUAL(board[10], INT8_C(0));
    CU_ASSERT_EQUAL(board[80], INT8_C(0));
    suwiz_board_free(board);

    board = suwiz_board_create("1..2..3..4..5006007008009");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    CU_ASSERT_EQUAL(board[0], INT8_C(1));
    CU_ASSERT_EQUAL(board[1], INT8_C(0));
    CU_ASSERT_EQUAL(board[2], INT8_C(0));
    CU_ASSERT_EQUAL(board[3], INT8_C(2));
    CU_ASSERT_EQUAL(board[4], INT8_C(0));
    CU_ASSERT_EQUAL(board[5], INT8_C(0));
    CU_ASSERT_EQUAL(board[6], INT8_C(3));
    CU_ASSERT_EQUAL(board[7], INT8_C(0));
    CU_ASSERT_EQUAL(board[8], INT8_C(0));
    CU_ASSERT_EQUAL(board[9], INT8_C(4));
    CU_ASSERT_EQUAL(board[10], INT8_C(0));
    CU_ASSERT_EQUAL(board[11], INT8_C(0));
    CU_ASSERT_EQUAL(board[12], INT8_C(5));
    CU_ASSERT_EQUAL(board[13], INT8_C(0));
    CU_ASSERT_EQUAL(board[14], INT8_C(0));
    CU_ASSERT_EQUAL(board[15], INT8_C(6));
    CU_ASSERT_EQUAL(board[16], INT8_C(0));
    CU_ASSERT_EQUAL(board[17], INT8_C(0));
    CU_ASSERT_EQUAL(board[18], INT8_C(7));
    CU_ASSERT_EQUAL(board[19], INT8_C(0));
    CU_ASSERT_EQUAL(board[20], INT8_C(0));
    CU_ASSERT_EQUAL(board[21], INT8_C(8));
    CU_ASSERT_EQUAL(board[22], INT8_C(0));
    CU_ASSERT_EQUAL(board[23], INT8_C(0));
    CU_ASSERT_EQUAL(board[24], INT8_C(9));
    CU_ASSERT_EQUAL(board[25], INT8_C(0));
    CU_ASSERT_EQUAL(board[26], INT8_C(0));
    CU_ASSERT_EQUAL(board[80], INT8_C(0));
    suwiz_board_free(board);
}

void test_suwiz_board_free(void) {

}

void test_suwiz_board_print(void) {
    char board_str[82] = {0};
    int8_t *board = NULL;

    board = suwiz_board_create("");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    suwiz_board_print(board, board_str);
    CU_ASSERT_STRING_EQUAL(board_str, ".................................................................................");
    suwiz_board_free(board);

    board = suwiz_board_create("123456789");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    suwiz_board_print(board, board_str);
    CU_ASSERT_STRING_EQUAL(board_str, "123456789........................................................................");
    suwiz_board_free(board);

    board = suwiz_board_create("1..2..3..4..5006007008009");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    suwiz_board_print(board, board_str);
    CU_ASSERT_STRING_EQUAL(board_str, "1..2..3..4..5..6..7..8..9........................................................");
    suwiz_board_free(board);

    board = suwiz_board_create("4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    suwiz_board_print(board, board_str);
    CU_ASSERT_STRING_EQUAL(board_str, "4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......");
    suwiz_board_free(board);
}

void test_suwiz_board_status(void) {
    int8_t *board = NULL;

    CU_ASSERT_EQUAL(suwiz_board_status(NULL), SUWIZ_BOARD_STATUS_INVALID);

    board = suwiz_board_create("");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    CU_ASSERT_EQUAL(suwiz_board_status(board), SUWIZ_BOARD_STATUS_UNSOLVED);
    suwiz_board_free(board);

    board = suwiz_board_create("123456789");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    CU_ASSERT_EQUAL(suwiz_board_status(board), SUWIZ_BOARD_STATUS_UNSOLVED);
    suwiz_board_free(board);

    board = suwiz_board_create("1..2..3..4..5006007008009");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    CU_ASSERT_EQUAL(suwiz_board_status(board), SUWIZ_BOARD_STATUS_UNSOLVED);
    suwiz_board_free(board);

    board = suwiz_board_create("4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    CU_ASSERT_EQUAL(suwiz_board_status(board), SUWIZ_BOARD_STATUS_UNSOLVED);
    suwiz_board_free(board);

    board = suwiz_board_create("111");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    CU_ASSERT_EQUAL(suwiz_board_status(board), SUWIZ_BOARD_STATUS_INVALID);
    suwiz_board_free(board);

    board = suwiz_board_create("712348956389567124456192837138425769264719385975836412897651243523984671641273598");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    CU_ASSERT_EQUAL(suwiz_board_status(board), SUWIZ_BOARD_STATUS_SOLVED);
    suwiz_board_free(board);
}