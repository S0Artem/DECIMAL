#ifndef DECIMAL_BASE_TIPES_H_
#define DECIMAL_BASE_TIPES_H_

typedef enum { S21_POSITIVE = 0, S21_NEGATIVE = 1 } s21_decimal_sign;

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef union {
  unsigned int i;
  struct {
    unsigned int empty2 : 16;
    unsigned power : 8;
    unsigned empty1 : 7;
    unsigned sign : 1;
  } parts;
} decimal_bit3;

#endif // DECIMAL_BASE_TIPES_H_