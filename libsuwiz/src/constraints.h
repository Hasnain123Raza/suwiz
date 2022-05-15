#ifndef CONSTRAINTS_H
#define CONSTRAINTS_H

#include <stdint.h>
#include <stdlib.h>
#include "common.h"

enum SuwizConstraintsStatus {
    SUWIZ_CONSTRAINTS_STATUS_INVALID,
    SUWIZ_CONSTRAINTS_STATUS_SOLVED,
    SUWIZ_CONSTRAINTS_STATUS_UNSOLVED,
    SUWIZ_CONSTRAINTS_STATUS_UNSOLVABLE
};

int16_t *suwiz_constraints_create();
void suwiz_constraints_free(int16_t *constraints);

enum SuwizConstraintsStatus suwiz_constraints_status(int16_t *constraints);
void suwiz_constraints_solve(int16_t *constraints, int index, int choice);
void suwiz_constraints_unsolve(int16_t *constraints, int index);

#endif