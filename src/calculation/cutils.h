#ifndef SRC_CALCULATION_CUTILS_H_
#define SRC_CALCULATION_CUTILS_H_

#define EPS 1E-6
#define PI 3.14159265358979323846

#include "../types.h"
#include "../parser/parser.h"
#include "../stack/clstack.h"

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
cflag rcalc(token* postfix_tokens, size_t plength, double* ans, double x);

/**
 * @brief           Runs calculation on arithmetic operations ('+', '-', 'mod', etc.)
 * 
 * @param stk       Pointer to stack object
 * @param operator  Operator to calculate
 * @param x         Dependent input variable
 * @return          If arithmetic operation performed successfully flag
 */
cflag acalc(clstack* stk, char operator, double x);

/**
 * @brief            Performs given operation and pushes result onto the stack
 * 
 * @param stk        Pointer to the stack object
 * @param flag       Pointer to the calculation flag 
 * @param operation  Operation to perform
 * @return           None (only runs calculation and pushes result onto the stack)
 */
void paoperation(clstack* stk, cflag* flag, char operation);

/**
 * @brief      Checks if there are at least two double values in the stack
 * 
 * @param stk  Pointer to the stack object
 * @return     If currect stack state is suitable for calculations
 */
bool vstack(clstack* stk);

#endif  // SRC_CALCULATION_CUTILS_H_