#ifndef DECIMAL_MAIN_TEST_H_
#define DECIMAL_MAIN_TEST_H_

#include <check.h>

TCase *create_s21_is_correct_decimal_tcase(void);

TCase *create_s21_decimal_set_bits_from_string_tcase(void);

TCase *create_ss21_decimal_from_strings_tcase(void);

Suite *decimal_suite(void);


#endif // DECIMAL_MAIN_TEST_H_