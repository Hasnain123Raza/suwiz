#ifndef TEST_CONSTRAINTS_H
#define TEST_CONSTRAINTS_H

#include <stdint.h>
#include <BCUnit/BCUnit.h>
#include <BCUnit/Basic.h>
#include "constraints.h"

int init_suite_constraints(void);
int clean_suite_constraints(void);
CU_ErrorCode prepare_suite_constraints(void);

void test_suwiz_constraints_is_value(void);
void test_suwiz_constraints_add_choice(void);
void test_suwiz_constraints_remove_choice(void);
void test_suwiz_constraints_has_choice(void);
void test_suwiz_constraints_create(void);
void test_suwiz_constraints_free(void);
void test_suwiz_constraints_status(void);
void test_suwiz_constraints_solve(void);
void test_suwiz_constraints_unsolve(void);

#endif