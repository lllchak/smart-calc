#include "cutils.h"

cflag rcalc(token* postfix_tokens, size_t plength, double* ans, double x) {
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

    clstack stk = {0};
    _csinit(&stk);
    cflag flag = SUCCESS;

    for (size_t i = 0; i < plength && flag == SUCCESS; i++) {
        if (postfix_tokens[i].is_num) {
            _cspush(&stk, postfix_tokens[i].num_var);
        }
        else {
            flag = acalc(&stk, postfix_tokens[i].operator, x);
            // flag = fcalc();
        }
    }

    if (stk.size != 1) flag = FAILED_CALC;
    else {
        *ans = _cspop(&stk);
        if (fabs(*ans) < EPS) *ans = 0;
    }

    _csdestroy(&stk);

    return flag;
}

cflag acalc(clstack* stk, char operator, double x) {
    /*
    Description:
        Runs calculation on arithmetic operations ('+', '-', 'mod', etc.)
    
    Args:
        (clstack*) stk     : Pointer to the stack object
        (char) operator  : Operator to calculate
        (double) x       : Dependent input variable

    Returns:
        If arithmetic operation performed successfully flag
    */

    cflag flag = SUCCESS;

    switch (operator) {
        case 'x':
            _cspush(stk, x);
            break;
        
        case '+': {
            poperation(stk, &flag, operator);
            break;
        }

        case '*': {
            poperation(stk, &flag, operator);
            break;
        }

        case '-': {
            poperation(stk, &flag, operator);
            break;
        }

        case '/': {
            poperation(stk, &flag, operator);
            break;
        }
    }

    return flag;
}

void poperation(clstack* stk, cflag* flag, char operation) {
    /*
    Description:
        Performs given operation and pushes result onto the stack

    Args:
        (clstack*) stk   : Pointer to the stack object
        (cflag*) flag    : Pointer to the calculation flag
        (char) operation : Operation to perform

    Returns:
        None (only runs calculation and pushes result onto the stack)
    */

    double top = 0.0;

    if (vstack(stk)) {
        switch (operation) {
            case '+':
                _cspush(stk, _cspop(stk) + _cspop(stk));
                break;
            
            case '*':
                _cspush(stk, _cspop(stk) * _cspop(stk));
                break;

            case '-':
                top = _cspop(stk);
                _cspush(stk, _cspop(stk) - top);
                break;
            
            case '/':
                top = _cspop(stk);
                if (fabs(top) >= EPS) _cspush(stk, _cspop(stk) / top);
                else *flag = FAILED_CALC;
                break;
        }

    } else *flag = INVALID_STACK;
}

bool vstack(clstack* stk) {
    /*
    Description:
        Checks if there are at least two double values in the stack

    Args:
        (stack*) stk : Pointer to the stack object

    Returns:
        If currect stack state is suitable for calculations
    */

    return stk->head && stk->head->next;
}
