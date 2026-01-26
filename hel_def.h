#ifndef HELP_DEF_H
#define HELP_DEF_H

#include <./types.h>

int s21_is_correct_decimal(s21_decimal decimal);
int s21_decimal_set_bits_from_string(int *bits, char *str);
s21_decimal s21_decimal_form_streings(char *str1, char *str2, char *str3,
                                      char *str4);
int s21_decimal_get_empty1(s21_decimal value);
int s21_decimal_get_empty2(s21_decimal value);
int s21_decimal_get_sign(s21_decimal value);
int s21_decimal_get_power(s21_decimal value);
s21_decimal s21_decimal_from_array(int value1, int value2, int value3, int sign,
                                   int power);
int s21_decimal_set_sign(s21_decimal *value, int sign);
int s21_decimal_set_power(s21_decimal *value, int power);
void s21_decimal_clear(s21_decimal *value);
s21_decimal s21_decimal_get_zero(void);
s21_decimal s21_decimal_get_one(void);

#endif
