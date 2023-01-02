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

    if (cflag == SUCCESS) {
        for (size_t i = 0; i < ilength; i++) {
            if (infix_tokens[i].is_num) printf("%f ", infix_tokens[i].num_var);
            else printf("%c ", infix_tokens[i].operator);
        }
        printf("\n");

        for (size_t i = 0; i < plength; i++) {
            if (postfix_tokens[i].is_num) printf("%f ", postfix_tokens[i].num_var);
            else printf("%c ", postfix_tokens[i].operator);
        }
        printf("\n");
    }

    free(postfix_tokens);
    free(infix_tokens);

    return cflag;
}
