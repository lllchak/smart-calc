#ifndef SRC_PARSER_UTILS_H_
#define SRC_PARSER_UTILS_H_

#include "../types.h"

/**
 * @brief      Checks if given char is an operand
 * 
 * @param chr  Char to check
 * @return     If given char is an operand flag
 */
bool is_operand(const char chr);

/**
 * @brief      Checks if given char is a dot
 * 
 * @param chr  Char to check
 * @return     If given char is a dot flag
 */
bool is_dot(const char chr);

/**
 * @brief     Checks if given char is a number
 *
 * @param chr Char to check 
 * @return    If given char is a number flag
 */
bool is_num(const char chr);

/**
 * @brief            Checks if given func_name is a mod function
 * 
 * @param func_name  Name of the function
 * @return           If given function is a mod function 
 */
bool is_mod(const char* func_name);

/**
 * @brief      Converts given string to lowercase if needed
 * 
 * @param src  Source string
 * @return     Lowercase representation of source string
 */
string stolow(string src);

/**
 * @brief                    Write given operator to tokens array
 * 
 * @param curr_token         Current token array element
 * @param operator           Operator to write (e.g. +)
 * @param curr_equation_idx  Index pointing to current position at source equation
 * @param shift              Value indicating how much the source equation index should be shifted
 * @return                   None (only write operator value to given token)
 */
void write_op_token(token* curr_token, char operator, size_t* curr_equation_idx, size_t shift);

/**
 * @brief                    Writes new token tokens array and shifts current equation index by given value
 * 
 * @param curr_token         Current token to write into tokens array
 * @param operator           Operator as a character (e.g. '+')
 * @param num_tokens         Pointer to number of tokens (tokens array length)
 * @param curr_equation_idx  Pointer to current equation token (points to current equation char)
 * @param shift              Shift size
 * @return                   None (only writes new token and shift index by given value)
 */
void oshift(token* curr_token, char operator, size_t* num_tokens, size_t* curr_equation_idx, size_t shift);

/**
 * @brief       
 * 
 * @param snum               Converts string to real number
 * @param num                Pointer to resulting number
 * @param curr_equation_idx  Index pointing to current position at source equation
 * @return                   If string converted to double successfully flags
 */
bool stod(const string snum, double* num, size_t* curr_equation_idx);

/**
 * @brief            Checks if given func_name is an actual function name
 * 
 * @param src        Source equation
 * @param func_name  Func`s name (e.g sin)
 * @param shift      Pointer to shift value (shift index after check to the length of func_name)
 * @return           If func_name is an actual function name flag
 */
bool is_function(const char* src, const char* func_name, size_t* shift);

/**
 * @brief     Checks the operator priority
 * 
 * @param tk  Token data value
 * @return    Token`s operator priority
 */
int gpriority(token* tk);

/**
 * @brief      Compares two operators priority difference
 * 
 * @param ltk  Left-hand side operator
 * @param rtk  Right-hand side operator
 * @return     Priority value (if ltk > rtk => >0 else if ltk < rtk <0 else =0)
 */
int opriority(token* ltk, token* rtk);

#endif  // SRC_PARSER_UTILS_H_
