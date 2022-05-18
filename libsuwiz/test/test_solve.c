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

    if (CU_add_test(suite_solve, "test_suwiz_board_solve_recursive", test_suwiz_board_solve_recursive) == NULL) {
        return CU_get_error();
    }

    return CUE_SUCCESS;
}



void test_suwiz_board_solve_recursive(void) {
    int8_t *board_in = NULL;
    int8_t *board_out = NULL;
    int8_t **solutions = NULL;
    int solutions_count;

    CU_ASSERT_PTR_NULL(suwiz_board_solve_recursive(NULL, 0, NULL));

    board_in = NULL;
    board_out = NULL;
    solutions = NULL;
    board_in = suwiz_board_create("3.542.81.4879.15.6.29.5637485.793.416132.8957.74.6528.2413.9.655.867.192.965124.8");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board_in);
    board_out = suwiz_board_create("365427819487931526129856374852793641613248957974165283241389765538674192796512438");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board_out);
    solutions = suwiz_board_solve_recursive(board_in, -1, &solutions_count);
    CU_ASSERT_PTR_NOT_NULL_FATAL(solutions);
    CU_ASSERT_EQUAL(solutions_count, 1);
    CU_ASSERT_PTR_NOT_NULL_FATAL(solutions[0]);
    CU_ASSERT_EQUAL(memcmp(solutions[0], board_out, SUWIZ_BOARD_SIZE), 0);
    suwiz_board_free(solutions[0]);
    free(solutions);
    suwiz_board_free(board_out);
    suwiz_board_free(board_in);

    board_in = NULL;
    board_out = NULL;
    solutions = NULL;
    board_in = suwiz_board_create("..2.3...8.....8....31.2.....6..5.27..1.....5.2.4.6..31....8.6.5.......13..531.4..");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board_in);
    board_out = suwiz_board_create("672435198549178362831629547368951274917243856254867931193784625486592713725316489");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board_out);
    solutions = suwiz_board_solve_recursive(board_in, -1, &solutions_count);
    CU_ASSERT_PTR_NOT_NULL_FATAL(solutions);
    CU_ASSERT_EQUAL(solutions_count, 1);
    CU_ASSERT_PTR_NOT_NULL_FATAL(solutions[0]);
    CU_ASSERT_EQUAL(memcmp(solutions[0], board_out, SUWIZ_BOARD_SIZE), 0);
    suwiz_board_free(solutions[0]);
    free(solutions);
    suwiz_board_free(board_out);
    suwiz_board_free(board_in);

    board_in = NULL;
    board_out = NULL;
    solutions = NULL;
    board_in = suwiz_board_create("2957438614318659..8761925433874592166123874955492167387635241899286713541549386..");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board_in);
    board_out = suwiz_board_create("295743861431865927876192543387459216612387495549216738763524189928671354154938672");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board_out);
    solutions = suwiz_board_solve_recursive(board_in, -1, &solutions_count);
    CU_ASSERT_PTR_NOT_NULL_FATAL(solutions);
    CU_ASSERT_EQUAL(solutions_count, 2);
    CU_ASSERT_PTR_NOT_NULL_FATAL(solutions[0]);
    CU_ASSERT_EQUAL(memcmp(solutions[0], board_out, SUWIZ_BOARD_SIZE), 0);
    suwiz_board_free(board_out);
    board_out = suwiz_board_create("295743861431865972876192543387459216612387495549216738763524189928671354154938627");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board_out);
    CU_ASSERT_PTR_NOT_NULL_FATAL(solutions[1]);
    CU_ASSERT_EQUAL(memcmp(solutions[1], board_out, SUWIZ_BOARD_SIZE), 0);
    suwiz_board_free(solutions[0]);
    suwiz_board_free(solutions[1]);
    free(solutions);
    suwiz_board_free(board_out);
    suwiz_board_free(board_in);

    board_in = NULL;
    board_out = NULL;
    solutions = NULL;
    board_in = suwiz_board_create("712348956389567124456192837138425769264719385975836412897651243523984671641273598");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board_in);
    board_out = suwiz_board_create("712348956389567124456192837138425769264719385975836412897651243523984671641273598");
    CU_ASSERT_PTR_NOT_NULL_FATAL(board_out);
    solutions = suwiz_board_solve_recursive(board_in, -1, &solutions_count);
    CU_ASSERT_PTR_NOT_NULL_FATAL(solutions);
    CU_ASSERT_EQUAL(solutions_count, 1);
    CU_ASSERT_PTR_NOT_NULL_FATAL(solutions[0]);
    CU_ASSERT_EQUAL(memcmp(solutions[0], board_out, SUWIZ_BOARD_SIZE), 0);
    suwiz_board_free(solutions[0]);
    free(solutions);
    suwiz_board_free(board_out);
    suwiz_board_free(board_in);
}