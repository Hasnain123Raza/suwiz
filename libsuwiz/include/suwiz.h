#ifndef SUWIZ_H
#define SUWIZ_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

/**
 * @file suwiz.h
 * @brief The main header file for suwiz library.
 * 
 * @author Hasnain Raza 
 */

/**
 * @brief Creates a new sudoku board from the string representation.
 * 
 * @details A sudoku board is an array of 9x9 8 bit signed integers. The string
 * representation of the board is a string of 81 characters. The characters
 * represent the values of the board. The characters can be any of the digits
 * 0-9. The characters can also be the character '.' which means the cell is
 * empty. The string can be NULL or empty. All cells with no string 
 * representation are set to 0.
 * 
 * @param board_str The string representation of the sudoku board.
 * @return int8_t* The new sudoku board.
 */
int8_t *suwiz_board_create(char *board_str);
/**
 * @brief Frees the memory allocated for the sudoku board.
 * 
 * @param board The sudoku board to be freed.
 */
void suwiz_board_free(int8_t *board);

/**
 * @brief Prints the sudoku board to the given string buffer.
 * 
 * @details The string buffer must be at least 82 characters long (to allow null
 * character). The string representation of the board is a string of 81 characters.
 * The characters represent the values of the board. The characters can be any of
 * the digits 1-9 or the character '.' which means the cell is empty. The string
 * can not be NULL.
 * 
 * @param board The sudoku board to be printed.
 * @param board_str The string buffer to which the board is printed.
 */
void suwiz_board_print(int8_t *board, char *board_str);
/**
 * @brief Determines the status of the sudoku board.
 * 
 * @details The status of the board can be one of the following:
 * - SUWIZ_BOARD_STATUS_INVALID: The board is invalid.
 * - SUWIZ_BOARD_STATUS_SOLVED: The board is solved.
 * - SUWIZ_BOARD_STATUS_UNSOLVED: The board is unsolved.
 * 
 * @param board The sudoku board to be checked.
 * @return enum SuwizBoardStatus The status of the board.
 */
enum SuwizBoardStatus suwiz_board_status(int8_t *board);

#endif