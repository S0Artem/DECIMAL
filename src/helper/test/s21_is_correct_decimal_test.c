#include "helper/helper.h"

#include <check.h>

#include "main_test.h"

START_TEST(good_option)
{
    s21_decimal decimal1 = {{0,0,0,0}};
    ck_assert_int_eq(1,s21_is_correct_decimal(decimal1));

    s21_decimal decimal2 = {{0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0}};
    ck_assert_int_eq(1,s21_is_correct_decimal(decimal2));
}END_TEST

START_TEST(bits3_error)
{
    s21_decimal decimal1 = {{0,0,0,0xFFFF0000}};
    ck_assert_int_eq(0,s21_is_correct_decimal(decimal1));

    s21_decimal decimal2 = {{0,0,0,0x000000FF}};
    ck_assert_int_eq(0,s21_is_correct_decimal(decimal2));

    s21_decimal decimal3 = {{0,0,0,0x0000FF00}};
    ck_assert_int_eq(0,s21_is_correct_decimal(decimal3));
}END_TEST


TCase *create_s21_is_correct_decimal_tcase(void)
{
    TCase *tcase_s21_is_correct_decimal = tcase_create("tcase_s21_is_correct_decimal");
    tcase_add_test(tcase_s21_is_correct_decimal, good_option);
    tcase_add_test(tcase_s21_is_correct_decimal, bits3_error);
    return tcase_s21_is_correct_decimal;
}