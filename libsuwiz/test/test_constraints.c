#include "test_constraints.h"

int init_suite_constraints(void) {
    return 0;
}

int clean_suite_constraints(void) {
    return 0;
}

CU_ErrorCode prepare_suite_constraints(void) {
    CU_pSuite suite_constraints = CU_add_suite("constraints", init_suite_constraints, clean_suite_constraints);
    if (suite_constraints == NULL) {
        return CU_get_error();
    }

    if ((CU_add_test(suite_constraints, "test_suwiz_constraints_create", test_suwiz_constraints_create) == NULL) ||
        (CU_add_test(suite_constraints, "test_suwiz_constraints_free", test_suwiz_constraints_free) == NULL) ||
        (CU_add_test(suite_constraints, "test_suwiz_constraints_status", test_suwiz_constraints_status) == NULL) ||
        (CU_add_test(suite_constraints, "test_suwiz_constraints_solve", test_suwiz_constraints_solve) == NULL) ||
        (CU_add_test(suite_constraints, "test_suwiz_constraints_unsolve", test_suwiz_constraints_unsolve) == NULL)) {
        return CU_get_error();
    }

    return CUE_SUCCESS;
}



void test_suwiz_constraints_create(void) {

}

void test_suwiz_constraints_free(void) {

}

void test_suwiz_constraints_status(void) {

}

void test_suwiz_constraints_solve(void) {

}

void test_suwiz_constraints_unsolve(void) {
    
}