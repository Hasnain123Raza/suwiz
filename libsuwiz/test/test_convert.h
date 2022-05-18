#ifndef TEST_CONVERT_H
#define TEST_CONVERT_H

#include <stdint.h>
#include <BCUnit/BCUnit.h>
#include <BCUnit/Basic.h>
#include "convert.h"

int init_suite_convert(void);
int clean_suite_convert(void);
CU_ErrorCode prepare_suite_convert(void);

void test_suwiz_board_to_constraints(void);
void test_suwiz_constraints_to_board(void);

#endif