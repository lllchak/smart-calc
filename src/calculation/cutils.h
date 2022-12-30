#ifndef SRC_CALCULATION_CUTILS_H_
#define SRC_CALCULATION_CUTILS_H_

#define EPS 1E-6
#define PI 3.14159265358979323846

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
cflag rcalc(token* postfix_tokens, size_t plength, double* ans, token* tkcops);

/**
 * @brief           Runs calculation on arithmetic operations ('+', '-', 'mod', etc.)
 * 
 * @param stk       Pointer to stack object
 * @param operator  Operator to calculate
 * @param x         Dependent input variable
 * @return          If arithmetic operation performed successfully flag
 */
cflag acalc(stack* stk, char operator, token* tkcops);

/**
 * @brief      Checks if there are at least two double values in the stack
 * 
 * @param stk  Pointer to the stack object
 * @return     If currect stack state is suitable for calculations
 */
bool vstack(stack* stk);

void calctoken(token* tk1, token* tk2, token* res, char operator);

double poper(token* tk1, token* tk2, char operator);

/**
 * @brief           Creates token object with given attributes
 * 
 * @param is_num    Is token is a number bool flag
 * @param num_var   Numeric value attribute
 * @param operator  Character value attribute
 * @return          Token object
 */
token* ctoken(bool is_num, double num_var, char operator);

#endif  // SRC_CALCULATION_CUTILS_H_