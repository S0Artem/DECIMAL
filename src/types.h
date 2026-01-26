#ifndef TIPES_H
#define TIPES_H

typedef enum { S21_POSITIVE = 0, S21_NEGATIVE = 1 } s21_decimal_sign;

typedef struct {
  int bits[4];
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

#endif