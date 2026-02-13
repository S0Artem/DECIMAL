#include <stdio.h>
#include <string.h>
#include <math.h>

#include "base/types.h"
#include "helper/helper.h"
// TODO: посмотреть нормально
#define DECIMAL_SIZE 96

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int bit_1;
  int bit_2;
  int bit_result = 0;
  int t = 0;

  // decimal_bit3 value_1_bit3, value_2_bit3, result_bit3;
  // value_1_bit3.i = value_1.bits[3];
  // value_2_bit3.i = value_2.bits[3];
  // result_bit3.i = result->bits[3];
  // if(value_1_bit3.parts.power > value_2_bit3.parts.power){
  //   int power = value_1_bit3.parts.power - value_2_bit3.parts.power;
  // }

  for (int i = 0; i < DECIMAL_SIZE; i++) {
    bit_1 = get_bit(&value_1, i);
    bit_2 = get_bit(&value_2, i);
    bit_result = t ^ (bit_1 ^ bit_2);
    t = ((bit_1 ^ bit_2) & t) | (bit_1 & bit_2);
    set_bit(result, bit_result, i);
  }

  return 0;
}