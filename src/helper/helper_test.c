#include "helper/helper.h"

#include <check.h>

#include "main_test.h"

START_TEST(s21_is_correct_decimal_full_zero)
{
    s21_decimal decimal = {0,0,0,0};
    ck_assert_int_eq(1,s21_is_correct_decimal(decimal));
}END_TEST

START_TEST(s21_is_correct_decimal_nofull_zero)
{
    s21_decimal decimal = {0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0};
    ck_assert_int_eq(1,s21_is_correct_decimal(decimal));
}END_TEST

START_TEST(s21_is_correct_decimal_bits3_empty2_error)
{
    s21_decimal decimal = {0,0,0,0xFFFF0000};
    ck_assert_int_eq(0,s21_is_correct_decimal(decimal));
}END_TEST

START_TEST(s21_is_correct_decimal_bits3_empty1_error)
{
    s21_decimal decimal = {0,0,0,0x000000FF};
    ck_assert_int_eq(0,s21_is_correct_decimal(decimal));
}END_TEST

START_TEST(s21_is_correct_decimal_bits3_power_error)
{
    s21_decimal decimal = {0,0,0,0x0000FF00};
    ck_assert_int_eq(0,s21_is_correct_decimal(decimal));
}END_TEST

TCase *create_healper_tcase(void)
{
    TCase *tcase_helper = tcase_create("helper");
    tcase_add_test(tcase_helper, s21_is_correct_decimal_full_zero);
    tcase_add_test(tcase_helper, s21_is_correct_decimal_nofull_zero);
    tcase_add_test(tcase_helper, s21_is_correct_decimal_bits3_empty2_error);
    tcase_add_test(tcase_helper, s21_is_correct_decimal_bits3_empty1_error);
    tcase_add_test(tcase_helper, s21_is_correct_decimal_bits3_power_error);
    return tcase_helper;
}