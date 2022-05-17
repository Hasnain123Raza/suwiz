#include "test_solve.h"

int init_suite_solve(void) {
    return 0;
}

int clean_suite_solve(void) {
    return 0;
}

CU_ErrorCode prepare_suite_solve(void) {
    CU_pSuite suite_solve = CU_add_suite("solve", init_suite_solve, clean_suite_solve);
    if (suite_solve == NULL) {
        return CU_get_error();
    }

    if ((CU_add_test(suite_solve, "test_suwiz_board_to_constraints", test_suwiz_board_to_constraints) == NULL) ||
        (CU_add_test(suite_solve, "test_suwiz_constraints_to_board", test_suwiz_constraints_to_board) == NULL)) {
        return CU_get_error();
    }

    return CUE_SUCCESS;
}



void test_suwiz_board_to_constraints(void) {

}

void test_suwiz_constraints_to_board(void) {
    
}