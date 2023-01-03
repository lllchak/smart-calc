#ifndef SRC_TYPES_H_
#define SRC_TYPES_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <tgmath.h> 
#include <string.h>
#include <stdlib.h>

#define DUMMY_DOUBLE 22.0f/7.0
#define DUMMY_CHAR 64
#define token token_t
#define node node_t
#define stack stk_t
#define clnode cnode_t
#define clstack cstk_t
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

typedef struct cnode_s {
    double data;
    struct cnode_s* next;
} cnode_t;

typedef struct cstk_s {
    size_t size;
    clnode* head;
} cstk_t;

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

typedef enum ERR_FLAG {
    SUCCESS = 0,
    INVALID_TOKEN = 1,
    FAILED_CALC = 2,
    INVALID_STACK = 3,
    FAILED_ALLOC = 4,
    NULL_PTR = 5,
    INIT_ERROR = 6,
} eflag;

#endif  // SRC_TYPES_H_
