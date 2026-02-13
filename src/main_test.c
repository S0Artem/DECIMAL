#include "main_test.h"

#include <stdio.h>
#include <check.h>
#include <stdlib.h>


Suite *decimal_suite(void)
{
    Suite *suite = suite_create("decimal");

    TCase *tc = create_s21_is_correct_decimal_tcase();
    suite_add_tcase(suite, tc);

    tc = create_s21_decimal_set_bits_from_string_tcase();
    suite_add_tcase(suite, tc);

    tc = create_ss21_decimal_from_strings_tcase();
    suite_add_tcase(suite, tc);
    
    
    return suite;
}

int main(void)
{
    int failed_count;
    Suite *suite = decimal_suite();
    SRunner *suite_runner = srunner_create(suite);

    srunner_run_all(suite_runner, CK_NORMAL);
    failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}