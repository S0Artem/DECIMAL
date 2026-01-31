#include "helper/helper.h"

#include <stdio.h>
#include <string.h>

#include "base/types.h"

static inline int s21_decimal_get_empty2(const s21_decimal *value);
static inline int s21_decimal_get_empty1(const s21_decimal *value);

/**
 * проверка decimal в правильности  
 */
int s21_is_correct_decimal(const s21_decimal decimal) {
  int code = 1;
  if (s21_decimal_get_empty1(&decimal) != 0 ||
      s21_decimal_get_empty2(&decimal) != 0)
    code = 0;
  else {
    int power = s21_decimal_get_power(&decimal);
    if (power < 0 || power > 28) code = 0;
  }
  return code;
}

/**
 * Заполнение быиты числа bits из строки str
 */
int s21_decimal_set_bits_from_string(int *bits, const char *str) {
  int index = 0;
  int error = 0;
  int len = (int)strlen(str);
  for (int i = len - 1; i >= 0 && error == 0; i--) {
    if (str[i] == ' ') {
      continue;
    } else if (str[i] == '0' || str[i] == '1') {
      bits[index] = str[i];
    } else {
      error = 1;
    }
  }
  return error;
}

/**
 * Заполняет decimal строками
 */
s21_decimal s21_decimal_form_streings(const char *str1, const char *str2, const char *str3,
                                    const char *str4) {
  s21_decimal result;
  int error = 0;
  error = s21_decimal_set_bits_from_string(&result.bits[0], str1);

  if (error == 0) {
    error = s21_decimal_set_bits_from_string(&result.bits[1], str2);
  }

  if (error == 0) {
    error = s21_decimal_set_bits_from_string(&result.bits[2], str3);
  }

  if (error == 0) {
    error = s21_decimal_set_bits_from_string(&result.bits[3], str4);
  }

  if (error == 1) {
    s21_decimal_clear(&result);
    fprintf(stderr, "Предупреждение: ошибка в заполнении decimal строками");
  }

  return result;
}

/**
 * возвращает значение битов с 24 по 30 в bits[3]
 */
static inline int s21_decimal_get_empty1(const s21_decimal *value) {
  decimal_bit3 result;
  result.i = value->bits[3];
  return result.parts.empty1;
}

/**
 * возвращает значение битов с 0 по 15 в bits[3]
 */
static inline int s21_decimal_get_empty2(const s21_decimal *value) {
  decimal_bit3 result;
  result.i = value->bits[3];
  return result.parts.empty2;
}

/**
 * возрщает значени знака
 */
int s21_decimal_get_sign(const s21_decimal *value) {
  decimal_bit3 result;
  result.i = value->bits[3];
  return result.parts.sign;
}

/**
 * возрщает значени тепени
 */
int s21_decimal_get_power(const s21_decimal *value) {
  decimal_bit3 result;
  result.i = value->bits[3];
  return result.parts.power;
}

/**
 * создаем число по заданным числа в каждую ячейку и каждым параметром
 */
s21_decimal s21_decimal_from_array(int value1, int value2, int value3, int sign,
                                   int power) {
  int error = 0;
  s21_decimal result;
  s21_decimal_clear(&result);
  result.bits[0] = value1;
  result.bits[1] = value2;
  result.bits[2] = value3;

  error = s21_decimal_set_power(&result, power);

  if (error == 0) {
    error = s21_decimal_set_sign(&result, sign);
  }
  if (error == 1) {
    s21_decimal_clear(&result);
    fprintf(stderr,
           "Предупреждение: ошибка в записи знака %i или в записи степени %i в "
           "s21_decimal_from_array.\n",
           sign, power);
  }

  return result;
}

/**
 * задаем нужный знак
 */
int s21_decimal_set_sign(s21_decimal *value, int sign) {
  int error = 0;
  decimal_bit3 bits3;
  bits3.i = value->bits[3];
  if (sign == S21_POSITIVE) {
    bits3.parts.sign = S21_POSITIVE;
  } else if (sign == S21_NEGATIVE) {
    bits3.parts.sign = S21_NEGATIVE;
  } else {
    error = 1;
  }

  return error;
}

/**
 * задаем нужный степень
 */
int s21_decimal_set_power(s21_decimal *value, int power) {
  int error = 0;
  decimal_bit3 bits3;
  bits3.i = value->bits[3];
  if (power > -1 && power < 9) {
    bits3.parts.power = power;
  } else
    error = 1;
  return error;
}

/**
 * заполняет число нулями
 */
void s21_decimal_clear(s21_decimal *value) {
  value->bits[0] = 0;
  value->bits[1] = 0;
  value->bits[2] = 0;
  value->bits[3] = 0;
}

/**
 * возращает число равное нулю
 */
s21_decimal s21_decimal_get_zero(void) {
  s21_decimal result;
  s21_decimal_clear(&result);
  return result;
}

/**
 * возращает число равное еденицы
 */
s21_decimal s21_decimal_get_one(void) {
  s21_decimal result;
  s21_decimal_clear(&result);
  result.bits[0] = 1;
  return result;
}