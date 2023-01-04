#include "calculation.h"

eflag calculate(char* infix, double x, double* ans) {
    /*
    Description:
        Calculates given expression with Reverse Polish Notation (RPN)
    
    Args:
        (char*) infix : Infix entry of the expression
        (double) x     : Dependent input variable
        (double*) ans  : Pointer to the answer value

    Returns:
        If input equation calculated successfully flag
    */

    size_t ilength = 0;
    size_t plength = 0;
    token* infix_tokens = tokenize(infix, &ilength);
    token* postfix_tokens = NULL;

    eflag flag = SUCCESS;

    if (infix_tokens) {
        postfix_tokens = gpostfix(infix_tokens, ilength, &plength);
        if (postfix_tokens) {
            rcalc(postfix_tokens, plength, ans, x);
            free(postfix_tokens);
        } else flag = INVALID_STACK;
        free(infix_tokens);
    } else flag = INVALID_TOKEN;

    return flag;
}

// double* gresults(token* postfix, size_t plength, size_t respoints, double lx, double step, eflag* flag) {
//     /*
//     Description:
//         Generates resulting points array
    
//     Args:
//         (token*) postfix   : RPN tokens
//         (size_t) plength   : Length of RPN
//         (size_t) respoints : Number of resulting points
//         (double) lx        : Left border
//         (double) step      : Calculation step size
//         (eflag*) flag      : Pointer to flag value

//     Returns:
//         If equation calculated successfully flag
//     */
    
//     double tans = 0.0;
//     double* results = (double*)calloc(respoints, sizeof(double));

//     for (size_t i = 0; i < respoints && *flag == SUCCESS; i++) {
//         *flag = calculate(postfix, plength, lx, &tans);
//         results[i] = tans;
//         lx += step;
//     }

//     return results;
// }
