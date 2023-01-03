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
            fcalc(&stk, postfix_tokens[i].operator, &flag);
            acalc(&stk, postfix_tokens[i].operator, x, &flag);
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

void acalc(clstack* stk, char operator, double x, cflag* flag) {
    /*
    Description:
        Runs calculation on arithmetic operations ('+', '-', 'mod', etc.)
    
    Args:
        (clstack*) stk   : Pointer to the stack object
        (char) operator  : Operator to calculate
        (double) x       : Dependent input variable
        (cflag*) flag   : Pointer to calculation flag

    Returns:
        None (sets arithmetic operation performed successfully flag)
    */

    switch (operator) {
        case 'x':
            _cspush(stk, x);
            break;
        
        case '+':
            poperation(stk, flag, operator);
            break;

        case '*':
            poperation(stk, flag, operator);
            break;

        case '-':
            poperation(stk, flag, operator);
            break;

        case '/':
            poperation(stk, flag, operator);
            break;

        case 'm':
            poperation(stk, flag, operator);
            break;

        case '^':
            poperation(stk, flag, operator);
            break;

    }
}

void fcalc(clstack* stk, char operator, cflag* flag) {
    /*
    Description:
        Runs calculation on arithmetic operations (sin(x), cos, etc.)

    Args:
        (clstack*) stk  : Pointer to stack object
        (char) operator : Function to calculate
        (cflag*) flag   : Pointer to calculation flag

    Returns:
        None (sets arithmetic operation performed successfully flag)
    */

    switch(operator) {
        case SIN:
            poperation(stk, flag, operator);
            break;
        
        case COS:
            poperation(stk, flag, operator);
            break;

        case TAN:
            poperation(stk, flag, operator);
            break;

        case ASIN:
            poperation(stk, flag, operator);
            break;

        case ACOS:
            poperation(stk, flag, operator);
            break;

        case ATAN:
            poperation(stk, flag, operator);
            break;

        case SQRT:
            poperation(stk, flag, operator);
            break;

        case LOG:
            poperation(stk, flag, operator);
            break;

        case LN:
            poperation(stk, flag, operator);
            break;
    }
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

    switch (operation) {
        case '+': {
            if (vstack(stk)) _cspush(stk, _cspop(stk) + _cspop(stk));
            else *flag = INVALID_STACK;
            break;
        }
        
        case '*': {
            if (vstack(stk)) _cspush(stk, _cspop(stk) * _cspop(stk));
            else *flag = INVALID_STACK;
            break;
        }

        case '-': {
            if (vstack(stk)) {
                top = _cspop(stk);
                _cspush(stk, _cspop(stk) - top);
            } else *flag = INVALID_STACK;
            break;
        }
        
        case '/': {
            if (vstack(stk)) {
                top = _cspop(stk);
                if (fabs(top) >= EPS) _cspush(stk, _cspop(stk) / top);
                else *flag = FAILED_CALC;
            } else *flag = INVALID_STACK;
            break;
        }

        case 'm': {
            if (vstack(stk)) {
                top = _cspop(stk);
                if (fabs(top) >= EPS) _cspush(stk, fmod(_cspop(stk), top));
                else *flag = FAILED_CALC;
            } else *flag = INVALID_STACK;
            break;
        }

        case '^': {
            if (vstack(stk)) {
                top = _cspop(stk);
                _cspush(stk, powl(_cspop(stk), top));
            }
            break;
        }
        
        case SIN: {
            if (stk->head) _cspush(stk, sin(_cspop(stk)));
            else *flag = INVALID_STACK;
            break;
        }

        case COS: {
            if (stk->head) _cspush(stk, cos(_cspop(stk)));
            else *flag = INVALID_STACK;
            break;
        }

        case TAN: {
            if (stk->head) {
                top = _cspop(stk);
                if (fabs(cos(top)) >= EPS) _cspush(stk, tan(top));
                else *flag = FAILED_CALC;
            } else *flag = INVALID_STACK;
            break;
        }

        case ASIN: {
            if (stk->head) _cspush(stk, asin(_cspop(stk)));
            else *flag = INVALID_STACK;
            break;
        }

        case ACOS: {
            if (stk->head) _cspush(stk, acos(_cspop(stk)));
            else *flag = INVALID_STACK;
            break;
        }

        case ATAN: {
            if (stk->head) _cspush(stk, atan(_cspop(stk)));
            else *flag = INVALID_STACK;
            break;
        }

        case SQRT: {
            if (stk->head) {
                top = _cspop(stk);
                if (top >= 0) _cspush(stk, sqrt(top));
                else *flag = FAILED_CALC;
            } else *flag = INVALID_STACK;
            break;
        }

        case LOG: {
            if (stk->head) {
                top = _cspop(stk);
                if (top > EPS) _cspush(stk, log10(top));
                else *flag = FAILED_CALC;
            } else *flag = INVALID_STACK;
            break;
        }

        case LN: {
            if (stk->head) {
                top = _cspop(stk);
                if (top > EPS) _cspush(stk, log(top));
                else *flag = FAILED_CALC;
            } else *flag = INVALID_STACK;
            break;
        }

    }
}

bool vstack(clstack* stk) {
    /*
    Description:
        Checks if there are at least two double values in the stack

    Args:
        (clstack*) stk : Pointer to the stack object

    Returns:
        If currect stack state is suitable for calculations
    */

    return stk->head && stk->head->next;
}
