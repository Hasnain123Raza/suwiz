#ifndef CONSTRAINTS_H
#define CONSTRAINTS_H

#include <stdint.h>
#include <stdlib.h>
#include "common.h"

/**
 * @file solve.h
 * @brief The header for constraints board data structure.
 * 
 * @author Hasnain Raza 
 */

/**
 * @brief The status of a constraints board.
 */
enum SuwizConstraintsStatus {
    SUWIZ_CONSTRAINTS_STATUS_INVALID, /**< The constraints board is invalid. */
    SUWIZ_CONSTRAINTS_STATUS_SOLVED, /**< The constraints board is solved. */
    SUWIZ_CONSTRAINTS_STATUS_UNSOLVED, /**< The constraints board is unsolved. */
    SUWIZ_CONSTRAINTS_STATUS_UNSOLVABLE /**< The constraints board is unsolvable. */
};

/**
 * @brief Creates an empty constraints board.
 * 
 * @return int16_t* The new constraints board.
 */
int16_t *suwiz_constraints_create();
/**
 * @brief Frees the memory allocated for the constraints board.
 * 
 * @param constraints The constraints board to be freed.
 */
void suwiz_constraints_free(int16_t *constraints);

/**
 * @brief Determine the status of the constraints board.
 * 
 * @details The status of the constraints board can be one of the following:
 * - SUWIZ_CONSTRAINTS_STATUS_INVALID: The constraints board is invalid.
 * - SUWIZ_CONSTRAINTS_STATUS_SOLVED: The constraints board is solved.
 * - SUWIZ_CONSTRAINTS_STATUS_UNSOLVED: The constraints board is unsolved.
 * - SUWIZ_CONSTRAINTS_STATUS_UNSOLVABLE: The constraints board is unsolvable.
 * 
 * @param constraints The constraints board.
 * @return enum SuwizConstraintsStatus The status of the constraints board.
 */
enum SuwizConstraintsStatus suwiz_constraints_status(int16_t *constraints);
/**
 * @brief Solves a particular choice at the given index of the constraints board.
 * 
 * @details The choice is a single digit between 1 and 9. The index is a single
 * digit between 0 and 80. The choice is placed at the given index of the
 * constraints board. The given index should not already have a value. If the
 * given index already has a value, this function does nothing.
 * 
 * @param constraints The constraints board.
 * @param index The index into the board.
 * @param choice The choice to be solved.
 */
void suwiz_constraints_solve(int16_t *constraints, int index, int choice);
/**
 * @brief Unsolves a value at the given index of the constraints board.
 * 
 * @details The index is a single digit between 0 and 80. The given index should
 * have a value. If the given index does not have a value, this function does
 * nothing.
 * 
 * @param constraints The constraints board.
 * @param index The index into the board.
 */
void suwiz_constraints_unsolve(int16_t *constraints, int index);

#endif