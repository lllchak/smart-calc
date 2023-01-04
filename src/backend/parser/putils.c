#include "putils.h"

bool is_dot(const char chr) {
    /*
    Description:
        Checks if given char is a dot

    Args:
        (const char) chr : Char to check

    Returns:
        If given char is a dot flag
    */

    return chr == '.';
}

bool is_operand(const char chr) {
    /*
    Description:
        Checks if given char is an operand

    Args:
        (const char) chr : Char to check

    Returns:
        If given char is an operand flag
    */

    return chr == '/' || chr == '*' || chr == '-' || chr == '+' || 
           chr == '(' || chr == ')' || chr == 's' || chr == 'S' ||
           chr == 't' || chr == 'c' || chr == 'C' || chr == 'q' ||
           chr == 'l' || chr == 'L' || chr == 'm' || chr == 'T';
}

bool is_num(const char chr) {
    /*
    Description:
        Checks if given char is a number
    
    Args:
        (const char) chr : Char to check
    
    Returns:
        If given char is a number flag
    */

    return chr >= '0' && chr <= '9';
}

bool is_mod(const char* func_name) {
    /*
    Description:
        Checks if given func_name is a mod function

    Args:
        (const char*) func_name : Name of the function

    Returns:
        If given function is a mod function
    */

    return !strncmp(func_name, "mod", 3);
}

char* stolow(char* src) {
    /*
    Description:
        Converts given char* to lowercase if needed
    
    Args:
        (char*) : Source char*

    Returns:
        Lowercase representation of source char*
    */

    size_t length = strlen(src);
    char* result = (char*)malloc((length * sizeof(char)) + 1);
    if (!result) return NULL;

    for (size_t i = 0; i < length; i++) {
        result[i] = src[i];
        if (result[i] >= 'A' && result[i] <= 'Z') result[i] += 'a' - 'A';
    }
    result[length] = '\0';
    
    return result;
}

void write_op_token(token* curr_token, char operation, size_t* curr_equation_idx, size_t shift) {
    /*
    Description:
        Write given operation to tokens array

    Args:
        (token*) curr_token      : Current token array element
        (char) operation          : Operator to write (e.g. +)
        (int*) curr_equation_idx : Index pointing to current position at source equation
        (int) shift              : Value indicating how much the source equation index should be shifted

    Returns:
        None (only writes operation to given token)
    */

    curr_token->num_var = DUMMY_DOUBLE;
    curr_token->operation = operation;
    curr_token->is_num = false;

    (*curr_equation_idx) += shift;
}

void oshift(
    token* curr_token,
    char operation,
    size_t* num_tokens,
    size_t* curr_equation_idx, 
    size_t shift
) {
    /*
    Description:
        Writes new token tokens array and shifts current equation index by given value

    Args:
        (token*) curr_token         : Current token to write into tokens array
        (char) operation             : Operator as a character (e.g. '+')
        (size_t*) num_tokens        : Pointer to number of tokens (tokens array length)
        (size_t*) curr_equation_idx : Pointer to current equation token (points to current equation char)
        (size_t) shift              : Shift size

    Returns:
        None (only writes new token and shift index by given value)
    */

    write_op_token(curr_token, operation, curr_equation_idx, shift);
    (*num_tokens)++;
}

bool stod(const char* snum, double* num, size_t* curr_equation_idx) {
    /*
    Description:
        Converts char* to real number

    Args:
        (const char*) snum      : Number in char* representation
        (double*) num            : Pointer to resulting number
        (int*) curr_equation_idx : Index pointing to current position at source equation

    Returns:
        If char* converted to double successfully flag
    */

    while (snum[*curr_equation_idx] >= '0' && snum[*curr_equation_idx] <= '9') {
        *num = *num * 10 + (snum[*curr_equation_idx] - '0');
        (*curr_equation_idx)++;
    }

    int mant_size = 0;
    double mantissa = 0.0;

    if (is_dot(snum[*curr_equation_idx])) {
        (*curr_equation_idx)++;
        if (snum[*curr_equation_idx] == ' ') return true;
        else if (
            snum[*curr_equation_idx] < '0' || 
            snum[*curr_equation_idx] > '9'
        ) return false;

        while (snum[*curr_equation_idx] >= '0' && snum[*curr_equation_idx] <= '9') {
            mantissa = mantissa * 10 + (snum[*curr_equation_idx] - '0');
            (*curr_equation_idx)++;
            mant_size++;
        }
    }

    for (; mant_size > 0; mant_size--) mantissa /= 10;

    *num += mantissa;

    return true;
}

bool is_function(const char* src, const char* func_name, size_t* shift) {
    /*
    Description:
        Checks if given func_name is an actual function name

    Args:
        (const char*) src       : Source equation
        (const char*) func_name : Func`s name
        (size_t*) shift          : Pointer to shift value (shift index after check to the length of func_name)

    Returns:
        If func_name is an actual function name flag
    */

    size_t length = 0;
    bool flag = true;

    while (flag && func_name[length]) {
        if (src[length] == '\0') flag = false;
        else if (src[length] != func_name[length]) flag = false;
        length++;
    }

    if (flag && src[length] != '(' && strcmp(func_name, "mod")) flag = false;
    *shift = length;

    return flag;
}

int gpriority(token* tk) {
    /*
    Description:
        Checks the operation priority

    Args:
        (token*) tk : Token data value

    Returns:
        Token`s operation priority
    */

    int res = 0;

    switch (tk->operation) {
        case '(':
        case ')':
            break;
        case '+':
        case '-':
            res = 2;
            break;
        case '*':
        case '/':
        case MOD:
            res = 3;
            break;
        case '^':
        case SIN:
        case COS:
        case TAN:
        case ASIN:
        case ACOS:
        case ATAN:
        case SQRT:
        case LOG:
        case LN:
            res = 4;
            break;
    }

    return res;
}

int opriority(token* ltk, token* rtk) {
    /*
    Description:
        Compares two operations priority difference

    Args:
        (token*) ltk : Left-hand side operation
        (token*) rtk : Right-hand side operation

    Returns:
        Priority value (if ltk > rtk => >0 else if ltk < rtk <0 else =0)
    */

    return gpriority(ltk) - gpriority(rtk);
}
