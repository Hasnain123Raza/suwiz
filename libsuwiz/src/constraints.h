#ifndef CONSTRAINTS_H
#define CONSTRAINTS_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

/**
 * @file solve.h
 * @brief The header for constraints board data structure.
 * 
 * @details Functions are not guaranteed to be robust so use with caution (make sure
 * the arguments are valid).
 * 
 * @author Hasnain Raza 
 */

#define SUWIZ_CONSTRAINTS_CHOICE_ONE INT16_C(0b10000) /**< Choice for the value one. */
#define SUWIZ_CONSTRAINTS_CHOICE_TWO INT16_C(0b100000) /**< Choice for the value two. */
#define SUWIZ_CONSTRAINTS_CHOICE_THREE INT16_C(0b1000000) /**< Choice for the value three. */
#define SUWIZ_CONSTRAINTS_CHOICE_FOUR INT16_C(0b10000000) /**< Choice for the value four. */
#define SUWIZ_CONSTRAINTS_CHOICE_FIVE INT16_C(0b100000000) /**< Choice for the value five. */
#define SUWIZ_CONSTRAINTS_CHOICE_SIX INT16_C(0b1000000000) /**< Choice for the value six. */
#define SUWIZ_CONSTRAINTS_CHOICE_SEVEN INT16_C(0b10000000000) /**< Choice for the value seven. */
#define SUWIZ_CONSTRAINTS_CHOICE_EIGHT INT16_C(0b100000000000) /**< Choice for the value eight. */
#define SUWIZ_CONSTRAINTS_CHOICE_NINE INT16_C(0b1000000000000) /**< Choice for the value nine. */
#define SUWIZ_CONSTRAINTS_CHOICE_ALL INT16_C(0b1111111110000) /**< Choice for all values. */
#define SUWIZ_CONSTRAINTS_CHOICE_NONE INT16_C(0b0) /**< Choice for no values. */

#define SUWIZ_CONSTRAINTS_IS_VALUE(cell) ((cell) & INT16_C(0b1111)) /**< Checks if the cell is a value. */
#define SUWIZ_CONSTRAINTS_ADD_CHOICE(cell, choice) ((cell) | (choice)) /**< Adds a choice to the cell. */
#define SUWIZ_CONSTRAINTS_REMOVE_CHOICE(cell, choice) ((cell) & ~(choice)) /**< Removes a choice from the cell. */
#define SUWIZ_CONSTRAINTS_HAS_CHOICE(cell, choice) (((cell) & (choice)) == (choice)) /**< Checks if the cell has the choice. */
#define SUWIZ_CONSTRAINTS_INT_TO_CHOICE(value) (INT16_C(1) << (value + 3)) /**< Converts an integer to a choice. */
#define SUWIZ_CONSTRAINTS_CHOICE_COUNT(cell) (__builtin_popcount(cell)) /**< Counts the number of choices in the cell. */
#define SUWIZ_CONSTRAINTS_LOWEST_CHOICE(cell) (1 << __builtin_ctz(cell)) /**< Gets the lowest choice in the cell. */

/**
 * @brief The status of a constraints board.
 */
enum SuwizConstraintsStatus {
    SUWIZ_CONSTRAINTS_STATUS_INVALID, /**< The constraints board is invalid. */
    SUWIZ_CONSTRAINTS_STATUS_SOLVED, /**< The constraints board is solved. */
    SUWIZ_CONSTRAINTS_STATUS_UNSOLVED /**< The constraints board is unsolved. */
};

/**
 * @brief Creates an empty constraints board.
 * 
 * @return int16_t* The new constraints board.
 */
int16_t *suwiz_constraints_create();
/**
 * @brief Clones a constraints board.
 * 
 * @param constraints The constraints board to clone.
 * @return int16_t* The new constraints board.
 */
int16_t *suwiz_constraints_clone(int16_t *constraints);
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
void suwiz_constraints_solve(int16_t *constraints, int index, int16_t choice);
/**
 * @brief Solves all the single choice constraints in the constraints board.
 * 
 * @details The single choice constraints are the constraints where the cell
 * has only one choice. After a single choice constraints is solve, the
 * function will start at the beginning again to solve any new single choice
 * constraints. Constraints board is not guaranteed to be valid after this
 * function is called.
 * 
 * @param constraints The constraints board.
 * @return int 1 if board becomes invalid, 0 otherwise.
 */
int suwiz_constraints_solve_singles(int16_t *constraints);

#endif