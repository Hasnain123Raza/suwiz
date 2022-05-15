#ifndef SOLVE_H
#define SOLVE_H

#include <stdint.h>
#include <stdlib.h>
#include "constraints.h"

int16_t *suwiz_board_to_constraints(int8_t *board);
int8_t *suwiz_constraints_to_board(int16_t *constraints);

#endif