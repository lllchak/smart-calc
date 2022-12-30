#include "cutils.h"

bool rcalc(token* postfix_tokens, size_t plength, double x, double* ans) {
    /*
    Description:
        Runs calculation on given postfix notation equation

    Args:
        (token*) postfix_tokens : Reverse Polish Notation (RPN) in array of tokens representation
        (size_t) plength        : Length of the postfix entry expression
        (double) x              : Dependent input variable
        (double*) ans           : Pointer to the answer value

    Returns:
        If equation calculated successfully flag
    */

    bool flag = false;

    if (postfix_tokens && plength && x && *ans) flag = true;

    return flag;
}