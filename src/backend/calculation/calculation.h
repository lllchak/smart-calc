#ifndef SRC_CALCULATION_CALCULATION_H_
#define SRC_CALCULATION_CALCULATION_H_

#include "cutils.h"

/**
 * @brief         Calculates given expression with Reverse Polish Notation (RPN) 
 * 
 * @param infix   Infix entry of the expression
 * @param x       Dependent input variable
 * @param ans     Pointer to the answer value
 * @return        If input equation calculated successfully flag
 */
cflag calculate(token* postfix, size_t plength, double x, double* ans);

/**
 * @brief          Generates resulting points array
 * 
 * @param postfix  RPN tokens
 * @param plength  Length of PRN
 * @param lx       Left border
 * @param rx       Right border
 * @param step     Calculation step
 * @return         Array of points to draw graph with
 */
double* gresults(token* postfix, size_t plength, double lx, double rx, double step);

#endif  // SRC_CALCULATION_CALCULATION_H_