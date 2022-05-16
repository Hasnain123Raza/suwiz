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

    if ((CU_add_test(suite_constraints, "suwiz_constraints_is_value", test_suwiz_constraints_is_value) == NULL) ||
        (CU_add_test(suite_constraints, "suwiz_constraints_add_choice", test_suwiz_constraints_add_choice) == NULL) ||
        (CU_add_test(suite_constraints, "suwiz_constraints_remove_choice", test_suwiz_constraints_remove_choice) == NULL) ||
        (CU_add_test(suite_constraints, "suwiz_constraints_has_choice", test_suwiz_constraints_has_choice) == NULL) ||
        (CU_add_test(suite_constraints, "suwiz_constraints_create", test_suwiz_constraints_create) == NULL) ||
        (CU_add_test(suite_constraints, "suwiz_constraints_free", test_suwiz_constraints_free) == NULL) ||
        (CU_add_test(suite_constraints, "suwiz_constraints_status", test_suwiz_constraints_status) == NULL) ||
        (CU_add_test(suite_constraints, "suwiz_constraints_solve", test_suwiz_constraints_solve) == NULL)) {
        return CU_get_error();
    }

    return CUE_SUCCESS;
}



void test_suwiz_constraints_is_value(void) {

}

void test_suwiz_constraints_add_choice(void) {

}

void test_suwiz_constraints_remove_choice(void) {

}

void test_suwiz_constraints_has_choice(void) {

}

void test_suwiz_constraints_create(void) {
    int16_t *constraints = suwiz_constraints_create();
    CU_ASSERT_PTR_NOT_NULL_FATAL(constraints);
    CU_ASSERT_EQUAL(constraints[0], SUWIZ_CONSTRAINTS_CHOICE_ALL);
    CU_ASSERT_EQUAL(constraints[80], SUWIZ_CONSTRAINTS_CHOICE_ALL);
    suwiz_constraints_free(constraints);
}

void test_suwiz_constraints_free(void) {

}

void test_suwiz_constraints_status(void) {
    int16_t *constraints = NULL;

    CU_ASSERT_EQUAL(suwiz_constraints_status(constraints), SUWIZ_CONSTRAINTS_STATUS_INVALID);

    constraints = NULL;
    constraints = suwiz_constraints_create();
    CU_ASSERT_PTR_NOT_NULL_FATAL(constraints);
    constraints[0] = 1; constraints[1] = 2; constraints[2] = 3;
    constraints[3] = 4; constraints[4] = 5; constraints[5] = 6;
    constraints[6] = 7; constraints[7] = 8; constraints[8] = 9;
    constraints[9] = constraints[10] = constraints[11] = constraints[18] = constraints[19] = constraints[20] = \
        SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SIX | \
        SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[12] = constraints[13] = constraints[14] = constraints[21] = constraints[22] = constraints[23] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[15] = constraints[16] = constraints[17] = constraints[24] = constraints[25] = constraints[26] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SIX;
    constraints[27] = constraints[36] = constraints[45] = constraints[54] = constraints[63] = constraints[72] = \
        SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | SUWIZ_CONSTRAINTS_CHOICE_FOUR | \
        SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | \
        SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[28] = constraints[37] = constraints[46] = constraints[55] = constraints[64] = constraints[73] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_THREE | SUWIZ_CONSTRAINTS_CHOICE_FOUR | \
        SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | \
        SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[29] = constraints[38] = constraints[47] = constraints[56] = constraints[65] = constraints[74] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_FOUR | \
        SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | \
        SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[30] = constraints[39] = constraints[48] = constraints[57] = constraints[66] = constraints[75] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | \
        SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[31] = constraints[40] = constraints[49] = constraints[58] = constraints[67] = constraints[76] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | \
        SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[32] = constraints[41] = constraints[50] = constraints[59] = constraints[68] = constraints[77] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | \
        SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[33] = constraints[42] = constraints[51] = constraints[60] = constraints[69] = constraints[78] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SIX | \
        SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[34] = constraints[43] = constraints[52] = constraints[61] = constraints[70] = constraints[79] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SIX | \
        SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[35] = constraints[44] = constraints[53] = constraints[62] = constraints[71] = constraints[80] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SIX | \
        SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_EIGHT;
    CU_ASSERT_EQUAL(suwiz_constraints_status(constraints), SUWIZ_CONSTRAINTS_STATUS_UNSOLVED);
    suwiz_constraints_free(constraints);

    constraints = NULL;
    constraints = suwiz_constraints_create();
    CU_ASSERT_PTR_NOT_NULL_FATAL(constraints);
    constraints[0] = 1; constraints[3] = 2; constraints[6] = 3;
    constraints[9] = 4; constraints[12] = 5; constraints[15] = 6;
    constraints[18] = 7; constraints[21] = 8; constraints[24] = 9;
    constraints[1] = constraints[2] = SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SIX | \
        SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[4] = constraints[5] = SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_SIX | \
        SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[7] = constraints[8] = SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_FIVE | \
        SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_EIGHT;
    constraints[10] = constraints[11] = SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[13] = constraints[14] = SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[16] = constraints[17] = SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | \
        SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_EIGHT;
    constraints[19] = constraints[20] = SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SIX;
    constraints[22] = constraints[23] = SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_FIVE;
    constraints[25] = constraints[26] = SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | \
        SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_FIVE;
    constraints[27] = constraints[36] = constraints[45] = constraints[54] = constraints[63] = constraints[72] = \
        SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | SUWIZ_CONSTRAINTS_CHOICE_FIVE | \
        SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[30] = constraints[39] = constraints[48] = constraints[57] = constraints[66] = constraints[75] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_THREE | SUWIZ_CONSTRAINTS_CHOICE_FOUR | \
        SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[33] = constraints[42] = constraints[51] = constraints[60] = constraints[69] = constraints[78] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_FOUR | \
        SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_EIGHT;
    constraints[28] = constraints[29] = constraints[31] = constraints[32] = constraints[34] = constraints[35] = \
        constraints[37] = constraints[38] = constraints[40] = constraints[41] = constraints[43] = constraints[44] = \
        constraints[46] = constraints[47] = constraints[49] = constraints[50] = constraints[52] = constraints[53] = \
        constraints[55] = constraints[56] = constraints[58] = constraints[59] = constraints[61] = constraints[62] = \
        constraints[64] = constraints[65] = constraints[67] = constraints[68] = constraints[70] = constraints[71] = \
        constraints[73] = constraints[74] = constraints[76] = constraints[77] = constraints[79] = constraints[80] = \
        SUWIZ_CONSTRAINTS_CHOICE_ALL;
    CU_ASSERT_EQUAL(suwiz_constraints_status(constraints), SUWIZ_CONSTRAINTS_STATUS_UNSOLVED);
    suwiz_constraints_free(constraints);

    constraints = NULL;
    constraints = suwiz_constraints_create();
    CU_ASSERT_PTR_NOT_NULL_FATAL(constraints);
    constraints[0] = 1; constraints[1] = 2; constraints[2] = 3;
    constraints[9] = 4; constraints[11] = 6; constraints[13] = 5;
    constraints[18] = 7; constraints[19] = 8; constraints[20] = 9;
    constraints[3] = constraints[4] = constraints[5] = constraints[6] = constraints[7] = constraints[8] = \
        SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | \
        SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[10] = SUWIZ_CONSTRAINTS_CHOICE_NONE;
    constraints[12] = constraints[14] = constraints[15] = constraints[16] = constraints[17] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[21] = constraints[22] = constraints[23] = constraints[24] = constraints[25] = constraints[26] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_SIX;
    constraints[27] = constraints[36] = constraints[45] = constraints[54] = constraints[63] = constraints[72] = \
        SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | SUWIZ_CONSTRAINTS_CHOICE_FIVE | \
        SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[28] = constraints[37] = constraints[46] = constraints[55] = constraints[64] = constraints[73] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_THREE | SUWIZ_CONSTRAINTS_CHOICE_FOUR | \
        SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | \
        SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[29] = constraints[38] = constraints[47] = constraints[56] = constraints[65] = constraints[74] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_FOUR | \
        SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_EIGHT;
    constraints[31] = constraints[40] = constraints[49] = constraints[58] = constraints[67] = constraints[76] = \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | \
        SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    constraints[30] = constraints[39] = constraints[48] = constraints[57] = constraints[66] = constraints[75] = \
        constraints[32] = constraints[41] = constraints[50] = constraints[59] = constraints[68] = constraints[77] = \
        constraints[33] = constraints[42] = constraints[51] = constraints[60] = constraints[69] = constraints[78] = \
        constraints[34] = constraints[43] = constraints[52] = constraints[61] = constraints[70] = constraints[79] = \
        constraints[35] = constraints[44] = constraints[53] = constraints[62] = constraints[71] = constraints[80] = \
        SUWIZ_CONSTRAINTS_CHOICE_ALL;
    CU_ASSERT_EQUAL(suwiz_constraints_status(constraints), SUWIZ_CONSTRAINTS_STATUS_INVALID);
    suwiz_constraints_free(constraints);

    constraints = NULL;
    constraints = suwiz_constraints_create();
    CU_ASSERT_PTR_NOT_NULL_FATAL(constraints);
    constraints[0] = INT16_C(7); constraints[1] = INT16_C(1); constraints[2] = INT16_C(2); constraints[3] = INT16_C(3); constraints[4] = INT16_C(4); constraints[5] = INT16_C(8); constraints[6] = INT16_C(9); constraints[7] = INT16_C(5); constraints[8] = INT16_C(6);
    constraints[9] = INT16_C(3); constraints[10] = INT16_C(8); constraints[11] = INT16_C(9); constraints[12] = INT16_C(5); constraints[13] = INT16_C(6); constraints[14] = INT16_C(7); constraints[15] = INT16_C(1); constraints[16] = INT16_C(2); constraints[17] = INT16_C(4);
    constraints[18] = INT16_C(4); constraints[19] = INT16_C(5); constraints[20] = INT16_C(6); constraints[21] = INT16_C(1); constraints[22] = INT16_C(9); constraints[23] = INT16_C(2); constraints[24] = INT16_C(8); constraints[25] = INT16_C(3); constraints[26] = INT16_C(7);
    constraints[27] = INT16_C(1); constraints[28] = INT16_C(3); constraints[29] = INT16_C(8); constraints[30] = INT16_C(4); constraints[31] = INT16_C(2); constraints[32] = INT16_C(5); constraints[33] = INT16_C(7); constraints[34] = INT16_C(6); constraints[35] = INT16_C(9);
    constraints[36] = INT16_C(2); constraints[37] = INT16_C(6); constraints[38] = INT16_C(5); constraints[39] = INT16_C(7); constraints[40] = INT16_C(1); constraints[41] = INT16_C(9); constraints[42] = INT16_C(3); constraints[43] = INT16_C(8); constraints[44] = INT16_C(5);
    constraints[45] = INT16_C(9); constraints[46] = INT16_C(7); constraints[47] = INT16_C(5); constraints[48] = INT16_C(8); constraints[49] = INT16_C(3); constraints[50] = INT16_C(6); constraints[51] = INT16_C(4); constraints[52] = INT16_C(1); constraints[53] = INT16_C(2);
    constraints[54] = INT16_C(8); constraints[55] = INT16_C(9); constraints[56] = INT16_C(7); constraints[57] = INT16_C(6); constraints[58] = INT16_C(5); constraints[59] = INT16_C(1); constraints[60] = INT16_C(2); constraints[61] = INT16_C(4); constraints[62] = INT16_C(3);
    constraints[63] = INT16_C(5); constraints[64] = INT16_C(2); constraints[65] = INT16_C(3); constraints[66] = INT16_C(9); constraints[67] = INT16_C(8); constraints[68] = INT16_C(4); constraints[69] = INT16_C(6); constraints[70] = INT16_C(7); constraints[71] = INT16_C(1);
    constraints[72] = INT16_C(6); constraints[73] = INT16_C(4); constraints[74] = INT16_C(1); constraints[75] = INT16_C(2); constraints[76] = INT16_C(7); constraints[77] = INT16_C(3); constraints[78] = INT16_C(5); constraints[79] = INT16_C(9); constraints[80] = INT16_C(8);
    CU_ASSERT_EQUAL(suwiz_constraints_status(constraints), SUWIZ_CONSTRAINTS_STATUS_SOLVED);
    suwiz_constraints_free(constraints);
}

void test_suwiz_constraints_solve(void) {
    int16_t *constraints = NULL;
    
    int16_t choice_23456789 = SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_THREE | SUWIZ_CONSTRAINTS_CHOICE_FOUR | \
        SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | \
        SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;
    int16_t choice_3456789 = SUWIZ_CONSTRAINTS_CHOICE_THREE | SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_FIVE | \
        SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_EIGHT | \
        SUWIZ_CONSTRAINTS_CHOICE_NINE;
    int16_t choice_12456789 = SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_FOUR | \
        SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | \
        SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE;

    constraints = NULL;
    constraints = suwiz_constraints_create();
    CU_ASSERT_PTR_NOT_NULL_FATAL(constraints);
    suwiz_constraints_solve(constraints, 0, 1);
    CU_ASSERT_EQUAL(constraints[0], INT16_C(1));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[1], choice_23456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[8], choice_23456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[9], choice_23456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[72], choice_23456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[10], choice_23456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[20], choice_23456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[12], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[17], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[28], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[73], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[30], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    suwiz_constraints_solve(constraints, 1, 2);
    CU_ASSERT_EQUAL(constraints[0], INT16_C(1));
    CU_ASSERT_EQUAL(constraints[1], INT16_C(2));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[2], choice_3456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[8], choice_3456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[9], choice_3456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[72], choice_3456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[10], choice_3456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[73], choice_3456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[11], choice_3456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[20], choice_3456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[12], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[17], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[21], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[26], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[30], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[29], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[74], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    suwiz_constraints_solve(constraints, 70, 3);
    CU_ASSERT_EQUAL(constraints[0], INT16_C(1));
    CU_ASSERT_EQUAL(constraints[1], INT16_C(2));
    CU_ASSERT_EQUAL(constraints[70], INT16_C(3));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[2], choice_3456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[8], choice_3456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[9], choice_3456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[72], choice_3456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[10], choice_3456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[73], choice_3456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[7], \
        SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SIX | \
        SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[63], \
        SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_FIVE | \
        SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_EIGHT | \
        SUWIZ_CONSTRAINTS_CHOICE_NINE));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[64], \
        SUWIZ_CONSTRAINTS_CHOICE_ONE | SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_FIVE | \
        SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_EIGHT | \
        SUWIZ_CONSTRAINTS_CHOICE_NINE));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[61], choice_12456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[16], choice_12456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[69], choice_12456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[65], choice_12456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[60], choice_12456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[62], choice_12456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[78], choice_12456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[80], choice_12456789));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[12], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[21], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[30], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[29], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[24], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[26], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[56], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[74], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[77], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[59], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[50], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[51], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[53], SUWIZ_CONSTRAINTS_CHOICE_ALL));
    suwiz_constraints_free(constraints);
}