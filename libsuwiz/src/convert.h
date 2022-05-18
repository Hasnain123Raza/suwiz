#ifndef CONVERT_H
#define CONVERT_H

#include <stdint.h>
#include <stdlib.h>
#include "common.h"
#include "constraints.h"
#include "suwiz.h"

/**
 * @file convert.h
 * @brief The header for converting between sudoku boards and constraints.
 * 
 * @author Hasnain Raza 
 */

/**
 * @brief Converts the sudoku board to a constraints board.
 * 
 * @param board The sudoku board.
 * @return int16_t* The constraints board.
 */
int16_t *suwiz_board_to_constraints(int8_t *board);

/**
 * @brief Converts the constraints board to a sudoku board.
 * 
 * @param constraints The constraints board.
 * @return int8_t* The sudoku board.
 */
int8_t *suwiz_constraints_to_board(int16_t *constraints);

#endif