#ifndef DECIMAL_HELPER_HELPER_H_
#define DECIMAL_HELPER_HELPER_H_

#include "base/types.h"

int s21_is_correct_decimal(const s21_decimal decimal);
int s21_decimal_set_bits_from_string(int *bits, const char *str);
s21_decimal s21_decimal_form_streings(const char *str1, const char *str2, const char *str3,
                                    const char *str4);
int s21_decimal_get_sign(const s21_decimal *value);
int s21_decimal_get_power(const s21_decimal *value);
s21_decimal s21_decimal_from_array(int value1, int value2, int value3, int sign,
                                   int power);
int s21_decimal_set_sign(s21_decimal *value, int sign);
int s21_decimal_set_power(s21_decimal *value, int power);
void s21_decimal_clear(s21_decimal *value);
s21_decimal s21_decimal_get_zero(void);
s21_decimal s21_decimal_get_one(void);

#endif // DECIMAL_HELPER_HELPER_H_