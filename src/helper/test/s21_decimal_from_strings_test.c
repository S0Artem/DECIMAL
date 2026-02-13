#include "main_test.h"

#include <check.h>

#include "helper/helper.h"

START_TEST(good_option_1)
{
    char str1[] = "00000000000000000000000000000000";
    char str2[] = "00000000000000000000000000000000";
    char str3[] = "00000000000000000000000000000000";
    char str4[] = "00000000000000000000000000000000";
    

    s21_decimal expected = {{0,0,0,0}};

    s21_decimal result = s21_decimal_from_strings(str1,str2,str3,str4);

    ck_assert_int_eq(result.bits[0],expected.bits[0]);
    ck_assert_int_eq(result.bits[1],expected.bits[1]);
    ck_assert_int_eq(result.bits[2],expected.bits[2]);
    ck_assert_int_eq(result.bits[3],expected.bits[3]);
}END_TEST

START_TEST(good_option_2)
{
    char str1[] = "00000000000000000000000000000001";
    char str2[] = "00000000000000000000000000000010";
    char str3[] = "00000000000000000000000000000011";
    char str4[] = "00000000000000000000000000000100";
    

    s21_decimal expected = {{1,2,3,4}};

    s21_decimal result = s21_decimal_from_strings(str1,str2,str3,str4);

    ck_assert_int_eq(result.bits[0],expected.bits[0]);
    ck_assert_int_eq(result.bits[1],expected.bits[1]);
    ck_assert_int_eq(result.bits[2],expected.bits[2]);
    ck_assert_int_eq(result.bits[3],expected.bits[3]);
}END_TEST

START_TEST(error_option)
{
    char str1[] = "00000000000000000000000000000002";
    char str2[] = "00000000000000000000000000000002";
    char str3[] = "00000000000000000000000000000002";
    char str4[] = "00000000000000000000000000000002";
    

    s21_decimal expected = {{0,0,0,0}};

    s21_decimal result = s21_decimal_from_strings(str1,str2,str3,str4);

    ck_assert_int_eq(result.bits[0],expected.bits[0]);
    ck_assert_int_eq(result.bits[1],expected.bits[1]);
    ck_assert_int_eq(result.bits[2],expected.bits[2]);
    ck_assert_int_eq(result.bits[3],expected.bits[3]);
}END_TEST

TCase *create_ss21_decimal_from_strings_tcase(void)
{
    TCase *tcase_create_s21_decimal_form_streings = tcase_create("tcase_create_s21_decimal_form_streings");

    tcase_add_test(tcase_create_s21_decimal_form_streings,good_option_1);
    tcase_add_test(tcase_create_s21_decimal_form_streings,good_option_2);
    tcase_add_test(tcase_create_s21_decimal_form_streings,error_option);


    return tcase_create_s21_decimal_form_streings;
}