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
#define SUWIZ_BOARD_INDEX_ROW(row, index) \
    ((row) * SUWIZ_BOARD_ROW_SIZE + (index))
/**
 * @brief Gets the index of a cell by an index into a column.
 */
#define SUWIZ_BOARD_INDEX_COLUMN(column, index) \
    ((index) * SUWIZ_BOARD_ROW_SIZE + (column))
/**
 * @brief Gets the index of a cell by an index into a box.
 */
#define SUWIZ_BOARD_INDEX_BOX(box, index) \
    (((box) / 3) * 27 + ((box) % 3) * 3 + ((index) / 3) * SUWIZ_BOARD_ROW_SIZE + ((index) % 3))

/**
 * @brief Gets the row corresponding to an index into a sudoku board.
 */
#define SUWIZ_BOARD_INDEX_TO_ROW(index) \
    ((index) / SUWIZ_BOARD_ROW_SIZE)
/**
 * @brief Gets the column corresponding to an index into a sudoku board.
 */
#define SUWIZ_BOARD_INDEX_TO_COLUMN(index) \
    ((index) % SUWIZ_BOARD_ROW_SIZE)
/**
 * @brief Gets the box corresponding to an index into a sudoku board.
 */
#define SUWIZ_BOARD_INDEX_TO_BOX(index) \
    (((index) / SUWIZ_BOARD_ROW_SIZE) / 3 * 3 + ((index) % SUWIZ_BOARD_ROW_SIZE) / 3)

#endif