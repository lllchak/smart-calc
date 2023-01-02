#include "calculation.h"

cflag calculate(string infix, double x, double* ans) {
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

    size_t ilength = 0;
    size_t plength = 0;
    token* infix_tokens = tokenize(infix, &ilength);
    token* postfix_tokens = NULL;

    cflag cflag = SUCCESS;

    if (infix_tokens) postfix_tokens = gpostfix(infix_tokens, ilength, &plength);
    else cflag = INVALID_TOKEN;

    cflag = rcalc(postfix_tokens, plength, ans, x);

    free(postfix_tokens);
    free(infix_tokens);

    return cflag;
}
