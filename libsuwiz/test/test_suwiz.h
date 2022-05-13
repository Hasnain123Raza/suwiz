#ifndef TEST_SUWIZ_H
#define TEST_SUWIZ_H

#include <BCUnit/BCUnit.h>
#include <BCUnit/Basic.h>
#include "suwiz.h"

int init_suite_suwiz(void);
int clean_suite_suwiz(void);
CU_ErrorCode prepare_suite_suwiz(void);

void test_suwiz_board_index_row(void);
void test_suwiz_board_index_column(void);
void test_suwiz_board_index_box(void);
void test_suwiz_board_create(void);
void test_suwiz_board_free(void);
void test_suwiz_board_print(void);
void test_suwiz_board_status(void);

#endif