#include "test_suwiz.h"

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

    if ((CU_add_test(suite_suwiz, "test_suwiz_board_create", test_suwiz_board_create) == NULL) ||
        (CU_add_test(suite_suwiz, "test_suwiz_board_free", test_suwiz_board_free) == NULL) ||
        (CU_add_test(suite_suwiz, "test_suwiz_board_print", test_suwiz_board_print) == NULL) ||
        (CU_add_test(suite_suwiz, "test_suwiz_board_status", test_suwiz_board_status) == NULL)) {
        return CU_get_error();
    }

    return CUE_SUCCESS;
}



void test_suwiz_board_create(void) {

}

void test_suwiz_board_free(void) {

}

void test_suwiz_board_print(void) {

}

void test_suwiz_board_status(void) {
    
}