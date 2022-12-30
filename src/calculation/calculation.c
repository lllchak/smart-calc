#include "calculation.h"

bool calculate(string infix, double x, double* ans) {
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
    bool flag = true;
    bool cflag = true;

    if (infix_tokens) postfix_tokens = gpostfix(infix_tokens, ilength, &plength);
    else flag = false;

    cflag = rcalc(postfix_tokens, plength, x, ans);

    free(postfix_tokens);

    return flag && cflag;
}
