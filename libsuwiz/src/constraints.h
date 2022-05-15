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

#define SUWIZ_CONSTRAINTS_CHOICE_ONE 0b10000 /**< Choice for the value one. */
#define SUWIZ_CONSTRAINTS_CHOICE_TWO 0b100000 /**< Choice for the value two. */
#define SUWIZ_CONSTRAINTS_CHOICE_THREE 0b1000000 /**< Choice for the value three. */
#define SUWIZ_CONSTRAINTS_CHOICE_FOUR 0b10000000 /**< Choice for the value four. */
#define SUWIZ_CONSTRAINTS_CHOICE_FIVE 0b100000000 /**< Choice for the value five. */
#define SUWIZ_CONSTRAINTS_CHOICE_SIX 0b1000000000 /**< Choice for the value six. */
#define SUWIZ_CONSTRAINTS_CHOICE_SEVEN 0b10000000000 /**< Choice for the value seven. */
#define SUWIZ_CONSTRAINTS_CHOICE_EIGHT 0b100000000000 /**< Choice for the value eight. */
#define SUWIZ_CONSTRAINTS_CHOICE_NINE 0b1000000000000 /**< Choice for the value nine. */

#define SUWIZ_CONSTRAINTS_IS_VALUE(cell) ((cell) & 0b1111) /**< Checks if the cell is a value. */
#define SUWIZ_CONSTRAINTS_ADD_CHOICE(cell, choice) ((cell) | (choice)) /**< Adds a choice to the cell. */
#define SUWIZ_CONSTRAINTS_REMOVE_CHOICE(cell, choice) ((cell) & ~(choice)) /**< Removes a choice from the cell. */
#define SUWIZ_CONSTRAINTS_HAS_CHOICE(cell, choice) ((cell) & (choice)) /**< Checks if the cell has the choice. */

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