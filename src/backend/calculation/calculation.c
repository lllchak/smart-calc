#include "calculation.h"

cflag calculate(token* postfix, size_t plength, double x, double* ans) {
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

double* gresults(token* postfix, size_t plength, double lx, double rx, double step) {
    /*
    Description:
        Generates resulting points array
    
    Args:
        (token*) postfix : RPN tokens
        (size_t) plength : Length of RPN
        (double) lx      : Left border
        (double) rx      : Right border
        (double) step    : Calculation step

    Returns:
        Array of points to draw graph with
    */

    size_t respoints = ceil((double)abs((int)lx - (int)rx) / step);
    double* results = (double*)calloc(respoints, sizeof(double));
    double tans = 0.0;

    for (size_t i = 0; i < respoints; i++) {
        calculate(postfix, plength, lx, &tans);
        results[i] = tans;
        lx += step;
    }

    return results;
}
