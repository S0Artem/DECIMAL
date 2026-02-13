#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>

#include "base/types.h"
#include "helper/helper.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int main() {
    s21_decimal dec;
    float f1 = 7.2532423423; 
    s21_from_float_to_decimal(f1, &dec);
    
    float f2;
    int result = s21_from_decimal_to_float(dec, &f2);
    
    printf("Исходное: %f\n", f1);
    printf("После конвертации туда-обратно: %f\n", f2);
    printf("Разница: %f\n", f1 - f2);
    printf("Ошибка: %d\n", result);
    
    return 0;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    int error = 0;
    
    int sign, power;
    decimal_bit3 bit3;
    bit3.i = src.bits[3];
    sign = bit3.parts.sign;
    power = bit3.parts.power;

    if (power > 28){
        error = 1;
    } else{
        unsigned long long low = 0;
        unsigned long long high = 0;
        low = (unsigned long long)src.bits[0] | ((unsigned long long)src.bits[1] << 32);
        high = (unsigned long long)src.bits[2];
        
        double doub = (double)low + (double)high * 18446744073709551616.0;

        for (int i = 0; i < power; i++) {
            doub /= 10.0;
        }

        if (sign) {
            doub = -doub;
        }
        if (doub > FLT_MAX || doub < -FLT_MAX) {
            *dst = (sign) ? -FLT_MAX : FLT_MAX;
            error = 1;
        } else {
            *dst = (float)doub; 
        }
    }
    return error;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst){

    int error = 0;

    if (fabsf(src) < 1e-28f) {
        error = 1;
        s21_decimal_clear(dst);
    }
    if (error == 0){
        double doub = fabs((double)src * 10000000.0);
        int sign = (src < 0.0f) ? 1 : 0;
        int power = 7;

        while (power > 0 && fmod(doub, 10.0) < 1e-10 && fmod(doub, 10.0) > -1e-10) {
            doub /= 10.0;
            power--;
        }

        if (doub >= 79228162514264337593543950336.0) {
            error = 1;
        }
        if (error == 0){
            s21_decimal_clear(dst);

            unsigned long long low = (unsigned long long)doub;
            unsigned long long high = (unsigned long long)(doub / 18446744073709551616.0);

            dst->bits[0] = (unsigned int)(low & 0xFFFFFFFF);          
            dst->bits[1] = (unsigned int)((low >> 32) & 0xFFFFFFFF);   
            dst->bits[2] = (unsigned int)(high & 0xFFFFFFFF);

            decimal_bit3 bit3;
            bit3.i = dst->bits[3];
            bit3.parts.sign = sign;
            bit3.parts.power = power;
            dst->bits[3] = bit3.i;
        }
    }

    
    return error;
}