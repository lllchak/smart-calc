#include "calculation.h"

eflag calculate(token* postfix, size_t plength, double x, double* ans) {
    /*
    Description:
        Calculates given expression with Reverse Polish Notation (RPN)
    
    Args:
        (string) infix : Infix entry of the expression
        (double) x     : Dependent input variable
        (double*) ans  : Pointer to the answer value

    Returns:
        If input equation calculated successfully flag
    */

    return rcalc(postfix, plength, ans, x);
}

double* gresults(token* postfix, size_t plength, size_t respoints, double lx, double step, eflag* flag) {
    /*
    Description:
        Generates resulting points array
    
    Args:
        (token*) postfix   : RPN tokens
        (size_t) plength   : Length of RPN
        (size_t) respoints : Number of resulting points
        (double) lx        : Left border
        (double) step      : Calculation step size
        (eflag*) flag      : Pointer to flag value

    Returns:
        If equation calculated successfully flag
    */
    
    double tans = 0.0;
    double* results = (double*)calloc(respoints, sizeof(double));

    for (size_t i = 0; i < respoints && *flag == SUCCESS; i++) {
        *flag = calculate(postfix, plength, lx, &tans);
        results[i] = tans;
        lx += step;
    }

    return results;
}
