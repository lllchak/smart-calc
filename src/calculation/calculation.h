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

double* gresults(token* postfix, size_t plength, double lx, double rx, double step);

#endif  // SRC_CALCULATION_CALCULATION_H_