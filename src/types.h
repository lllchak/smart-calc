#ifndef SRC_TYPES_H_
#define SRC_TYPES_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define DUMMY_DOUBLE 22.0f/7.0
#define DUMMY_CHAR 64
#define token token_t
#define node node_t
#define stack stk_t
#define string char*

typedef struct token_s {
    double num_var;
    char operator;
    bool is_num;
} token_t;

typedef struct node_s {
    token* data;
    struct node_s* next;
} node_t;

typedef struct stk_s {
    size_t size;
    node* head;
} stk_t;

typedef enum FUNC_CODE {
    SIN = 's',
    COS = 'c',
    TAN = 't',
    ASIN = 'S',
    ACOS = 'C',
    ATAN = 'T',
    SQRT = 'q',
    LOG = 'l',
    LN = 'L',
    MOD = 'm',
} func_code;

typedef enum DATA_TYPE {
    UNINIALIZED,
    NUMERIC,
    CHARACTER,
} dtype;

typedef enum SFLAG {
    OK,
    FAILED_ALLOC,
    NULL_PTR,
    INIT_ERROR,
} sflag;

#endif  // SRC_TYPES_H_
