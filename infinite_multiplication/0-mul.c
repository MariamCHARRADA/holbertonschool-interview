#include "holberton.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int is_all_digits(char *str);
void print_error_and_exit(void);

/**
 * main - Program that multiplies two positive numbers.
 * @argc: Argument count
 * @argv: Argument vector (array of strings)
 * Return: 0 on success, or exit with status 98 on error
 */
int main(int argc, char *argv[])
{
	long num1_int, num2_int, result;

	if (argc != 3)
		print_error_and_exit();

	if (!is_all_digits(argv[1]) || !is_all_digits(argv[2]))
		print_error_and_exit();

	num1_int = atol(argv[1]);
	num2_int = atol(argv[2]);
	result	 = num1_int * num2_int;

	printf("%ld\n", result);

	return (0);
}

/**
 * is_all_digits - Checks if a string contains only digits.
 * @str: The string to check.
 * Return: 1 if the string contains only digits, 0 otherwise.
 */
int is_all_digits(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

/**
 * print_error_and_exit - Prints "Error" and exits with status 98.
 */
void print_error_and_exit(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}
