#include "test_suwiz.h"

static int8_t *sample_board = {
    0,  1,  2,      3,  4,  5,     6,  7,  8,
    9,  10, 11,    12, 13, 14,    15, 16, 17,
    18, 19, 20,    21, 22, 23,    24, 25, 26,

    27, 28, 29,    30, 31, 32,    33, 34, 35,
    36, 37, 38,    39, 40, 41,    42, 43, 44,
    45, 46, 47,    48, 49, 50,    51, 52, 53,

    54, 55, 56,    57, 58, 59,    60, 61, 62,
    63, 64, 65,    66, 67, 68,    69, 70, 71,
    72, 73, 74,    75, 76, 77,    78, 79, 80
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

}

void test_suwiz_board_index_column(void) {

}

void test_suwiz_board_index_box(void) {

}

void test_suwiz_board_create(void) {

}

void test_suwiz_board_free(void) {

}

void test_suwiz_board_print(void) {

}

void test_suwiz_board_status(void) {
    
}