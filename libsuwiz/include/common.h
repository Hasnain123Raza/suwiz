#ifndef COMMON_H
#define COMMON_H

/**
 * @file common.h
 * @brief Contains common definitions and macros.
 * 
 * @author Hasnain Raza 
 */

#define SUWIZ_BOARD_ROWS 9 /**< The number of rows in a sudoku board. */
#define SUWIZ_BOARD_COLUMNS 9 /**< The number of columns in a sudoku board. */
#define SUWIZ_BOARD_BOXES 9 /**< The number of boxes in a sudoku board. */

#define SUWIZ_BOARD_ROW_SIZE 9 /**< The number of cells in a row of a sudoku board. */
#define SUWIZ_BOARD_COLUMN_SIZE 9 /**< The number of cells in a column of a sudoku board. */
#define SUWIZ_BOARD_BOX_SIZE 9 /**< The number of cells in a box of a sudoku board. */
#define SUWIZ_BOARD_SIZE 81 /**< The number of cells in a sudoku board. */

/**
 * @brief Gets the index of a cell by an index into a row.
 */
#define SUWIZ_BOARD_INDEX_ROW(row, index) 0
/**
 * @brief Gets the index of a cell by an index into a column.
 */
#define SUWIZ_BOARD_INDEX_COLUMN(column, index) 0
/**
 * @brief Gets the index of a cell by an index into a box.
 */
#define SUWIZ_BOARD_INDEX_BOX(box, index) 0

/**
 * @brief The status of a sudoku board.
 */
enum SuwizBoardStatus {
    SUWIZ_BOARD_STATUS_INVALID, /**< The board is invalid. */
    SUWIZ_BOARD_STATUS_SOLVED, /**< The board is solved. */
    SUWIZ_BOARD_STATUS_UNSOLVED /**< The board is unsolved. */
};

#endif