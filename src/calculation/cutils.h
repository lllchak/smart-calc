#ifndef SRC_CALCULATION_CUTILS_H_
#define SRC_CALCULATION_CUTILS_H_

#include "../types.h"
#include "../parser/parser.h"
#include "../stack/stack.h"

#include <math.h>
#include <tgmath.h> 

/**
 * @brief                 Runs calculation on given postfix notation equation
 * 
 * @param postfix_tokens  Reverse Polish Notation (RPN) in array of tokens representation
 * @param plength         Length of the postfix entry expression
 * @param x               Dependent input variable
 * @param ans             Pointer to the answer value
 * @return                If equation calculated successfully flag
 */
bool rcalc(token* postfix_tokens, size_t plength, double x, double* ans);

#endif  // SRC_CALCULATION_CUTILS_H_