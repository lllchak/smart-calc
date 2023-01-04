#ifndef SRC_CALCULATION_CALCULATION_H_
#define SRC_CALCULATION_CALCULATION_H_

#include "cutils.h"

/**
 * @brief        Calculates given expression with Reverse Polish Notation (RPN) 
 * 
 * @param infix  Infix entry of the expression
 * @param x      Dependent input variable
 * @param ans    Pointer to the answer value
 * @return       If input equation calculated successfully flag
 */
eflag calculate(string infix, double x, double* ans);

// /**
//  * @brief           Generates resulting points array
//  * 
//  * @param postfix    RPN tokens
//  * @param plength    Length of PRN
//  * @param respoints  Number of resulting points
//  * @param lx         Left border
//  * @param step       Calculation step size
//  * @param flag       Pointer to flag value
//  * @return           If equation calculated successfully flag
//  */
// double* gresults(token* postfix, size_t plength, size_t respoints, double lx, double step, eflag* flag);

#endif  // SRC_CALCULATION_CALCULATION_H_