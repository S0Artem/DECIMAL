CC = gcc

CFLAGS = -I. -Wall -Wextra -Werror
LDFLAGS = -lcheck -lm -lpthread -lsubunit

SRC = helper/helper.c
TEST_SRC = main_test.c \
          helper/test/s21_is_correct_decimal_test.c \
          helper/test/s21_decimal_set_bits_from_string_test.c \
		  helper/test/s21_decimal_from_strings_test.c


TEST_PROGRAM = test_program


# Правило по умолчанию
#all: $(TARGET)

test: $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) -o $(TEST_PROGRAM) $(TEST_SRC) $(SRC) $(LDFLAGS)

run: $(TEST_PROGRAM)
	./$(TEST_PROGRAM)

clean:
	rm -f $(TEST_PROGRAM)

.PHONY: all run clean