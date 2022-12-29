# SmartCalc v1.0

## Contents
0. [Task](#task)
1. [Polish Notation](#polish-notation-and-reverse-polish-notation)
2. [Implementation of the Algorithm](#implementation-of-the-algorithm)
3. [Operators](#operators)

## Task
The main task of that project is to implement smart calculator app with credit and deposit calculations support. Project should be build as an desktop app via make utility.

### Polish Notation and Reverse Polish Notation (RPN)

Despite the absolute convenience of working with the classical form of writing expressions, when it comes to writing programs, queries are most often formed in the format `what to do -> what data to perform operations with`. So, around 1920, the Polish logician Jan Lukasiewicz invented  prefix notation (later also called Polish notation or normal Polish notation) in order to simplify propositional logic.

Let's take a look at the ways to write expressions:

The expression written in conventional infix notation:

>2 / (3 + 2) * 5

The expression written in Polish prefix notation:

>\* (/ 2 (+ 3 2)) 5

Normally parentheses between operations of equal priority are unnecessary and the final expression looks like this:

>\* / 2 (+ 3 2) 5

The Polish notation is widely used in the field of computing, in particular it is used in many stack-oriented programming languages such as PostScript, and for a long time it was the basis for many calculating machines (calculators).

In the mid-1950s, the Australian philosopher and computer scientist Charles Hamblin developed reverse polish notation (RPN). Hamblin's work was presented at a conference in June 1957, and published in 1957 and 1962.

Reverse Polish notation had all the advantages of the progenitor because it removes the need for parentheses which allows to reduce the volume of expressions. This had led to a decrease in the number of commands, when writing computer programs. That is why sometimes Reverse Polish notation is called Reverse bracketless notation.

The expression written in Reverse Polish (bracketless) notation:

> 2 3 2 + / 5 *

### Implementation of the Algorithm

Here is a lingocode to describe the reversing equation algorithm

```
For each token in tokens

    If the token is:
    - A number – put it into the output queue

    - A function or a left parenthesis – push it onto the stack

    - A function arguments separator (e.g. comma):
        - Move operators from the stack to the output queue until the token at the top of the stack is a left parenthesis. If there is no left parenthesis in the stack, there is an error in the expression.

    - Operator (O1):
        - While there is an token-operator O2 at the top of the stack, that has greater precedence than O1 or they have the same precedence and O1 is left-associative:
        - Pop O2 from the stack into the output queue
        - Push O1 onto the stack

    - A right parenthesis:
        - While the token at the top of the stack is not a left parenthesis, pop the token-operators from the stack into the output queue.
        - Pop the left parenthesis from the stack and discard it.
        - If there is a function token at the top of the stack, then pop the function from the stack into the output queue
        - If the stack ended before the left parenthesis was read, there is an error in the expression.

    If there are no more tokens left in the input string:
    - As long as there are operators in the stack:
        - If there is a parenthesis at the top of the stack - there is an error in the expression.
        - Pop the operator from the stack onto the output queue

End For
```

### Operators

Calculator should be able to process such operators and functions.

- **Arithmetic operators**:

    | Operator name | Infix notation <br /> (Classic) | Prefix notation <br /> (Polish notation) |  Postfix notation <br /> (Reverse Polish notation) |
    | --------- | ------ | ------ | ------ |
    | Brackets | (a + b) | (+ a b) | a b + |
    | Addition | a + b | + a b | a b + |
    | Subtraction | a - b | - a b | a b - |
    | Multiplication | a * b | * a b | a b * |
    | Division | a / b | / a b | a b \ |
    | Power | a ^ b | ^ a b | a b ^ |
    | Modulus | a mod b | mod a b | a b mod |
    | Unary plus | +a | +a | a+ |
    | Unary minus | -a | -a | a- |

    >Note that the multiplication operator contains the obligatory sign `*`. Processing an expression with the omitted `*` sign is optional and is left to the developer's decision

- **Functions**:

    | Function description | Function |
    | ------ | ------ |
    | Computes cosine | cos(x) |
    | Computes sine | sin(x) |
    | Computes tangent | tan(x) |
    | Computes arc cosine | acos(x) |
    | Computes arc sine | asin(x) |
    | Computes arc tangent | atan(x) |
    | Computes square root | sqrt(x) |
    | Computes natural logarithm | ln(x) |
    | Computes common logarithm | log(x) |
