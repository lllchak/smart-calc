#include <check.h>

#include "../backend/parser/parser.h"
#include "../backend/calculation/calculation.h"

START_TEST(ln_cos) {
    string equation = "ln(cos(x))";
    size_t length = 0, postfix_length = 0;
    token* infix = tokenize(equation, &length);
    token* postfix_expression = gpostfix(infix, length, &postfix_length);
    double answer = 0;
    int status = calculate(postfix_expression, postfix_length, PI, &answer);
    double result = 0;
    ck_assert_double_eq_tol(result, answer, 1e-7);
    ck_assert_int_eq(status, true);

    free(postfix_expression);
    free(infix);
}

START_TEST(ln_sin) {
    string equation = "ln(sin(x))";
    size_t length  = 0, postfix_length = 0;
    token* infix = tokenize(equation, &length);
    token* postfix_expression = gpostfix(infix, length, &postfix_length);
    double answer = 0;
    int status = calculate(postfix_expression, postfix_length, PI / 2, &answer);
    double result = 0;
    ck_assert_double_eq_tol(result, answer, 1e-7);
    ck_assert_int_eq(status, false);

    free(postfix_expression);
    free(infix);
}

START_TEST(ln_sin_incorrect_input) {
    string equation = "ln(sin(x)))";
    size_t length  = 0;
    token* infix = tokenize(equation, &length);
    ck_assert_ptr_null(infix);
}

START_TEST(sin_sqrt_4) {
    string equation = "sin(sqrt(4))";
    size_t length  = 0, postfix_length = 0;
    token* infix = tokenize(equation, &length);
    token* postfix_expression = gpostfix(infix, length, &postfix_length);
    double answer = 0;
    int status = calculate(postfix_expression, postfix_length, DUMMY_DOUBLE, &answer);
    double result = 0.909297;
    ck_assert_double_eq_tol(result, answer, 1e-3);
    ck_assert_int_eq(status, false);

    free(postfix_expression);
    free(infix);
}

START_TEST(simple_arithm) {
    string equation = "1 + 2 + 4 * 3 - 3 * 7";
    size_t length  = 0, postfix_length = 0;
    token* infix = tokenize(equation, &length);
    token* postfix_expression = gpostfix(infix, length, &postfix_length);
    double answer = 0;
    int status = calculate(postfix_expression, postfix_length, DUMMY_DOUBLE, &answer);
    double result = -6;
    ck_assert_double_eq_tol(result, answer, 1e-3);
    ck_assert_int_eq(status, false);

    free(postfix_expression);
    free(infix);
}

START_TEST(simple_arithm_2) {
    string equation = "(1 + 2 + 4 * 3 - 3 * 7) / 4";
    size_t length  = 0, postfix_length = 0;
    token* infix = tokenize(equation, &length);
    token* postfix_expression = gpostfix(infix, length, &postfix_length);
    double answer = 0;
    int status = calculate(postfix_expression, postfix_length, DUMMY_DOUBLE, &answer);
    double result = -1.5;
    ck_assert_double_eq_tol(result, answer, 1e-3);
    ck_assert_int_eq(status, false);

    free(postfix_expression);
    free(infix);
}

START_TEST(stress_test) {
    string equation = "acos(cos(sin(atan(ln(sqrt((8 * ((1 + 2 + 4 * 3 - 3 * 7) / 4)) + 133))))))";
    size_t length  = 0, postfix_length = 0;
    token* infix = tokenize(equation, &length);
    token* postfix_expression = gpostfix(infix, length, &postfix_length);
    double answer = 0;
    int status = calculate(postfix_expression, postfix_length, DUMMY_DOUBLE, &answer);
    double result = 0.922957;
    ck_assert_double_eq_tol(result, answer, 1e-3);
    ck_assert_int_eq(status, false);

    free(postfix_expression);
    free(infix);
}

START_TEST(unary) {
    string equation = "(-4 + 5) * 2";
    size_t length  = 0, postfix_length = 0;
    token* infix = tokenize(equation, &length);
    token* postfix_expression = gpostfix(infix, length, &postfix_length);
    double answer = 0;
    int status = calculate(postfix_expression, postfix_length, DUMMY_DOUBLE, &answer);
    double result = 2;
    ck_assert_double_eq_tol(result, answer, 1e-3);
    ck_assert_int_eq(status, false);

    free(postfix_expression);
    free(infix);
}

START_TEST(degree) {
    string equation = "2.5 ^ 2";
    size_t length  = 0, postfix_length = 0;
    token* infix = tokenize(equation, &length);
    token* postfix_expression = gpostfix(infix, length, &postfix_length);
    double answer = 0;
    int status = calculate(postfix_expression, postfix_length, DUMMY_DOUBLE, &answer);
    double result = 6.25;
    ck_assert_double_eq_tol(result, answer, 1e-1);
    ck_assert_int_eq(status, false);

    free(postfix_expression);
    free(infix);
}

START_TEST(degree_tan) {
    string equation = "tan(2.5 ^ 2.5)";
    size_t length  = 0, postfix_length = 0;
    token* infix = tokenize(equation, &length);
    token* postfix_expression = gpostfix(infix, length, &postfix_length);
    double answer = 0;
    int status = calculate(postfix_expression, postfix_length, PI / 2, &answer);
    double result = 0.49140;
    ck_assert_double_eq_tol(result, answer, 1e-1);
    ck_assert_int_eq(status, false);
    free(postfix_expression);
    free(infix);
}

START_TEST(mod) {
    string equation = "6.25 mod 3";
    size_t length  = 0, postfix_length = 0;
    token* infix = tokenize(equation, &length);
    token* postfix_expression = gpostfix(infix, length, &postfix_length);
    double answer = 0;
    int status = calculate(postfix_expression, postfix_length, PI / 2, &answer);
    double result = 0.25;
    ck_assert_double_eq_tol(result, answer, 1e-1);
    ck_assert_int_eq(status, false);
    free(postfix_expression);
    free(infix);
}

START_TEST(asin_degree_mod) {
    string equation = "asin(0.2)";
    size_t length  = 0, postfix_length = 0;
    token* infix = tokenize(equation, &length);
    token* postfix_expression = gpostfix(infix, length, &postfix_length);
    double answer = 0;
    int status = calculate(postfix_expression, postfix_length, PI / 2, &answer);
    double result = 0.201358;
    ck_assert_double_eq_tol(result, answer, 1e-1);
    ck_assert_int_eq(status, false);
    free(postfix_expression);
    free(infix);
}

START_TEST(brackets) {
    string equation = "()";
    size_t length  = 0, postfix_length = 0;
    token* infix = tokenize(equation, &length);
    double answer = 0;
    token* postfix_expression = gpostfix(infix, length, &postfix_length);
    int status = calculate(postfix_expression, postfix_length, PI / 2, &answer);
    // Calculation error
    ck_assert_int_eq(status, INVALID_TOKEN);

    free(postfix_expression);
    free(infix);
}

START_TEST(exponent) {
    string equation = "exp";
    size_t length  = 0, postfix_length = 0;
    token* infix = tokenize(equation, &length);
    double answer = 0;
    token* postfix_expression = gpostfix(infix, length, &postfix_length);
    int status = calculate(postfix_expression, postfix_length, PI / 2, &answer);
    // Calculation error
    double result = 2.718282;
    ck_assert_double_eq_tol(result, answer, 1e-3);
    ck_assert_int_eq(status, false);

    free(postfix_expression);
    free(infix);
}

int main() {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Calculations");
    SRunner *sr = srunner_create(s1);

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, ln_cos);
    tcase_add_test(tc1_1, ln_sin);
    tcase_add_test(tc1_1, ln_sin_incorrect_input);
    tcase_add_test(tc1_1, sin_sqrt_4);
    tcase_add_test(tc1_1, simple_arithm);
    tcase_add_test(tc1_1, simple_arithm_2);
    tcase_add_test(tc1_1, stress_test);
    tcase_add_test(tc1_1, unary);
    tcase_add_test(tc1_1, degree);
    tcase_add_test(tc1_1, degree_tan);
    tcase_add_test(tc1_1, mod);
    tcase_add_test(tc1_1, brackets);
    tcase_add_test(tc1_1, asin_degree_mod);
    tcase_add_test(tc1_1, exponent);

    srunner_run_all(sr, CK_ENV);
    int nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}