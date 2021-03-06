#include "test_convert.h"

int init_suite_convert(void) {
    return 0;
}

int clean_suite_convert(void) {
    return 0;
}

CU_ErrorCode prepare_suite_convert(void) {
    CU_pSuite suite_convert = CU_add_suite("convert", init_suite_convert, clean_suite_convert);
    if (suite_convert == NULL) {
        return CU_get_error();
    }

    if ((CU_add_test(suite_convert, "test_suwiz_board_to_constraints", test_suwiz_board_to_constraints) == NULL) ||
        (CU_add_test(suite_convert, "test_suwiz_constraints_to_board", test_suwiz_constraints_to_board) == NULL)) {
        return CU_get_error();
    }

    return CUE_SUCCESS;
}



void test_suwiz_board_to_constraints(void) {
    int8_t *board = NULL;
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

    board = NULL;
    constraints = NULL;
    board = suwiz_board_create("12....................................................................3..........");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    constraints = suwiz_board_to_constraints(board);
    CU_ASSERT_PTR_NOT_NULL_FATAL(constraints);
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
    suwiz_board_free(board);

    board = NULL;
    constraints = NULL;
    board = suwiz_board_create("4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    constraints = suwiz_board_to_constraints(board);
    CU_ASSERT_PTR_NOT_NULL_FATAL(constraints);
    CU_ASSERT_EQUAL(constraints[0], INT16_C(4));
    CU_ASSERT_EQUAL(constraints[6], INT16_C(8));
    CU_ASSERT_EQUAL(constraints[8], INT16_C(5));
    CU_ASSERT_EQUAL(constraints[10], INT16_C(3));
    CU_ASSERT_EQUAL(constraints[21], INT16_C(7));
    CU_ASSERT_EQUAL(constraints[28], INT16_C(2));
    CU_ASSERT_EQUAL(constraints[34], INT16_C(6));
    CU_ASSERT_EQUAL(constraints[40], INT16_C(8));
    CU_ASSERT_EQUAL(constraints[42], INT16_C(4));
    CU_ASSERT_EQUAL(constraints[49], INT16_C(1));
    CU_ASSERT_EQUAL(constraints[57], INT16_C(6));
    CU_ASSERT_EQUAL(constraints[59], INT16_C(3));
    CU_ASSERT_EQUAL(constraints[61], INT16_C(7));
    CU_ASSERT_EQUAL(constraints[63], INT16_C(5));
    CU_ASSERT_EQUAL(constraints[66], INT16_C(2));
    CU_ASSERT_EQUAL(constraints[72], INT16_C(1));
    CU_ASSERT_EQUAL(constraints[74], INT16_C(4));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[16], SUWIZ_CONSTRAINTS_CHOICE_ONE | \
        SUWIZ_CONSTRAINTS_CHOICE_TWO | SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_NINE));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[68], SUWIZ_CONSTRAINTS_CHOICE_ONE | \
        SUWIZ_CONSTRAINTS_CHOICE_FOUR | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | SUWIZ_CONSTRAINTS_CHOICE_EIGHT | \
        SUWIZ_CONSTRAINTS_CHOICE_NINE));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[47], SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_SIX | SUWIZ_CONSTRAINTS_CHOICE_SEVEN | \
        SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[39], SUWIZ_CONSTRAINTS_CHOICE_THREE | \
        SUWIZ_CONSTRAINTS_CHOICE_FIVE | SUWIZ_CONSTRAINTS_CHOICE_NINE));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[56], SUWIZ_CONSTRAINTS_CHOICE_TWO | \
        SUWIZ_CONSTRAINTS_CHOICE_EIGHT | SUWIZ_CONSTRAINTS_CHOICE_NINE));
    suwiz_constraints_free(constraints);
    suwiz_board_free(board);

    board = NULL;
    constraints = NULL;
    board = suwiz_board_create("3.542.81.4879.15.6.29.5637485.793.416132.8957.74.6528.2413.9.655.867.192.965124.8");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board);
    constraints = suwiz_board_to_constraints(board);
    CU_ASSERT_PTR_NOT_NULL_FATAL(constraints);
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[1], SUWIZ_CONSTRAINTS_CHOICE_SIX));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[5], SUWIZ_CONSTRAINTS_CHOICE_SEVEN));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[8], SUWIZ_CONSTRAINTS_CHOICE_NINE));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[13], SUWIZ_CONSTRAINTS_CHOICE_THREE));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[16], SUWIZ_CONSTRAINTS_CHOICE_TWO));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[18], SUWIZ_CONSTRAINTS_CHOICE_ONE));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[21], SUWIZ_CONSTRAINTS_CHOICE_EIGHT));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[29], SUWIZ_CONSTRAINTS_CHOICE_TWO));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[33], SUWIZ_CONSTRAINTS_CHOICE_SIX));
    CU_ASSERT_TRUE(SUWIZ_CONSTRAINTS_HAS_CHOICE(constraints[40], SUWIZ_CONSTRAINTS_CHOICE_FOUR));
    suwiz_constraints_free(constraints);
    suwiz_board_free(board);
}

void test_suwiz_constraints_to_board(void) {

}