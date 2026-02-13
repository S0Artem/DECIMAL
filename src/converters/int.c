#include <stdio.h>
#include <string.h>

#include "base/types.h"
#include "helper/helper.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);

int main(int argc, char const *argv[])
{
    int number_int = 2567;
    s21_decimal number_decimal;
    if(s21_from_int_to_decimal(number_int, &number_decimal) != 1){
        printf("%c%u\n", 
            ((number_decimal.bits[3] >> 31) & 1) ? '-' : '+',
        number_decimal.bits[0]);
    }

    s21_decimal_set_power(&number_decimal, 1);
    if(s21_from_decimal_to_int(number_decimal, &number_int) != 1){
        printf("%i\n", number_int);
    }
    return 0;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst){
    int error = 0;
    s21_decimal_clear(dst);
    char buffer[12] = {0};
    sprintf (buffer, "%i", src);
    if(buffer[0] == '-'){
        s21_decimal_set_sign(dst, 1);
        dst->bits[0] = (unsigned int)(-src);
    } else{
        dst->bits[0] = (unsigned int)(src);
    }
    return error;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst){
    int error = 0;
    char buffer[12] = {0};
    decimal_bit3 bit3;
    bit3.i = src.bits[3];
    if(bit3.parts.sign == 1){
        buffer[0] = 1;
        sprintf (buffer+1, "%i", src.bits[0]);
        sscanf(buffer, "%i", *&dst);
    } else{
        *dst = src.bits[0];
    }
    *dst = *dst / s21_pow_int(10, bit3.parts.power);
    return error;
}