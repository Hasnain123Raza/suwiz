#ifndef TEST_SOLVE_H
#define TEST_SOLVE_H

#include <stdint.h>
#include <BCUnit/BCUnit.h>
#include <BCUnit/Basic.h>
#include "solve.h"

int init_suite_solve(void);
int clean_suite_solve(void);
CU_ErrorCode prepare_suite_solve(void);

void test_suwiz_board_to_constraints(void);
void test_suwiz_constraints_to_board(void);

#endif