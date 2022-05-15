#include <stdio.h>
#include <BCUnit/BCUnit.h>
#include <BCUnit/Basic.h>
#include "test_constraints.h"
#include "test_suwiz.h"

int main(void) {
    FILE *fp = fopen("test/driver.trs", "w");
    fclose(fp);
    fp = fopen("test/driver.log", "w");
    fclose(fp);

    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    if ((prepare_suite_suwiz() != CUE_SUCCESS) ||
        (prepare_suite_constraints() != CUE_SUCCESS)) {
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}