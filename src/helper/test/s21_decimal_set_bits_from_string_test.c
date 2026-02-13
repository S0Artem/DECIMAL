#include "helper/helper.h"

#include <check.h>

#include "main_test.h"

START_TEST(good_option)
{
    int bits = 0;
    char str1[] = "0000000000000000000000000000000";
    ck_assert_int_eq(s21_decimal_set_bits_from_string(&bits, str1), 0);
    
    char str2[] = "11111111111111111111111111111111";
    ck_assert_int_eq(s21_decimal_set_bits_from_string(&bits, str2), 0);
    
    char str3[] = "00000000000000000000000000000001";
    ck_assert_int_eq(s21_decimal_set_bits_from_string(&bits, str3), 0);

    char str4[] = "00000000000000 000000000000000001";
    ck_assert_int_eq(s21_decimal_set_bits_from_string(&bits, str4), 0);
}
END_TEST

START_TEST(error_option)
{
    int bits = 0;
    char str1[] = "00000006000000000000000000000000";
    ck_assert_int_eq(s21_decimal_set_bits_from_string(&bits, str1), 1);
    
    char str2[] = "11111111211111111111111111111111";
    ck_assert_int_eq(s21_decimal_set_bits_from_string(&bits, str2), 1);
    
    char str3[] = "00000000003000000000000000000001";
    ck_assert_int_eq(s21_decimal_set_bits_from_string(&bits, str3), 1);

    char str4[] = "00000000000000 000000000000200001";
    ck_assert_int_eq(s21_decimal_set_bits_from_string(&bits, str4), 1);
}
END_TEST



TCase *create_s21_decimal_set_bits_from_string_tcase(void){
    TCase *tcase_s21_decimal_set_bits_from_string = tcase_create("s21_decimal_set_bits_from_string");
    tcase_add_test(tcase_s21_decimal_set_bits_from_string,good_option);
    tcase_add_test(tcase_s21_decimal_set_bits_from_string,error_option);
    return tcase_s21_decimal_set_bits_from_string;
}