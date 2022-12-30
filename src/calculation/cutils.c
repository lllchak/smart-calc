#include "cutils.h"

cflag rcalc(token* postfix_tokens, size_t plength, double* ans, token* tkcops) {
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

    stack stk = {0};
    _sinit(&stk);
    cflag flag = SUCCESS;

    for (size_t i = 0; i < plength && flag == SUCCESS; i++) {
        if (postfix_tokens[i].is_num) {
            _spush(&stk, &(postfix_tokens[i]));
        }
        else {
            flag = acalc(&stk, postfix_tokens[i].operator, tkcops);
            // flag = fcalc();
        }
    }

    if (stk.size != 1 || !stk.head->data->is_num) flag = FAILED_CALC;
    else {
        *ans = _spop(&stk)->num_var;
        if (fabs(*ans) < EPS) *ans = 0;
    }

    _sdestroy(&stk);

    return flag;
}

cflag acalc(stack* stk, char operator, token* tkcops) {
    /*
    Description:
        Runs calculation on arithmetic operations ('+', '-', 'mod', etc.)
    
    Args:
        (stack*) stk    : Pointer to the stack object
        (char) operator : Operator to calculate
        (double) x      : Dependent input variable

    Returns:
        If arithmetic operation performed successfully flag
    */

    token* top = NULL;
    size_t copies_idx = 0;
    cflag flag = SUCCESS;

    switch (operator) {
        case 'x':
            copies_idx++;
            _spush(stk, &(tkcops[copies_idx]));
            break;
        
        case '+': {
            if (vstack(stk)) {
                calctoken(_spop(stk), _spop(stk), &(tkcops[copies_idx]), operator);
                _spush(stk, &(tkcops[copies_idx++]));
            } else flag = INVALID_STACK;
            break;
        }

        case '*': {
            if (vstack(stk)) {;
                calctoken(_spop(stk), _spop(stk), &(tkcops[copies_idx]), operator);
                _spush(stk, &(tkcops[copies_idx++]));
            } else flag = INVALID_STACK;
            break;
        }

        case '-': {
            if (vstack(stk)) {
                top = _spop(stk);
                calctoken(_spop(stk), top, &(tkcops[copies_idx]), operator);
                _spush(stk, &(tkcops[copies_idx++]));
            } else flag = INVALID_STACK;
            break;
        }

        case '/': {
            if (vstack(stk)) {
                top = _spop(stk);
                if (fabs(top->num_var) >= EPS) {
                    calctoken(_spop(stk), top, &(tkcops[copies_idx]), operator);
                    _spush(stk, &(tkcops[copies_idx++]));
                } else flag = FAILED_CALC;
            } else flag = INVALID_STACK;
            break;
        }
    }

    print_stack(stk);
    printf("\n");

    return flag;
}

bool vstack(stack* stk) {
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

void calctoken(token* tk1, token* tk2, token* res, char operator) {
    res->is_num = tk1->is_num;
    res->num_var = poper(tk1, tk2, operator);
    res->operator = tk1->operator;
}

double poper(token* tk1, token* tk2, char operator) {
    double res = 0.0;

    switch (operator) {
        case '+':
            res = tk1->num_var + tk2->num_var;
            break;
        
        case '*':
            res = tk1->num_var * tk2->num_var;
            break;

        case '-':
            res = tk1->num_var - tk2->num_var;
            break;

        case '/':
            res = tk1->num_var / tk2->num_var;
            break;
    }

    return res;
}

token* ctoken(bool is_num, double num_var, char operator) {
    /*
    Description:
        Creates token object with given attributes

    Args:
        (bool) is_num    : If token is a number bool flag
        (double) num_var : Numeric value attribute
        (char) operator  : Character value attribute

    Returns:
        If token initialized successfully flag
    */

    token* tk = (token*)calloc(1, sizeof(token));
    if (!tk) return NULL;

    tk->is_num = is_num;
    tk->num_var = num_var;
    tk->operator = operator;

    return tk;
}