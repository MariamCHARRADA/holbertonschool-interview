#include "holberton.h"
#include <stdlib.h>

/**
 * is_digit - checks if a string contains only digits.
 * @str: string to be checked.
 * Return: 1 if string contains only digits, otherwise 0.
 */
int is_digit(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * print_error - prints "Error" and exits with code 98.
 */
void print_error(void)
{
	char *msg = "Error";
	int i;

	for (i = 0; msg[i]; i++)
		_putchar(msg[i]);
	_putchar('\n');
	exit(98);
}

/**
 * _len - returns the length of a string.
 * @str: string to measure.
 * Return: length of the string.
 */
int _len(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

/**
 * main - multiplies two numbers and prints the result.
 * @argc: number of arguments.
 * @argv: array of argument values.
 * Return: 0 on success, or exit with code 98 on error.
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len_num1, len_num2, total_len, i, j, mul, sum, *result;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();
	num1 = argv[1];
	num2 = argv[2];

	len_num1  = _len(num1);
	len_num2  = _len(num2);
	total_len = len_num1 + len_num2;

	result = malloc(total_len * sizeof(int));
	if (result == NULL)
		print_error();
	for (i = 0; i < total_len; i++)
		result[i] = 0;
	for (i = len_num1 - 1; i >= 0; i--)
	{
		for (j = len_num2 - 1; j >= 0; j--)
		{
			mul				  = (num1[i] - '0') * (num2[j] - '0');
			sum				  = mul + result[i + j + 1];
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}
	i = 0;
	while (i < total_len && result[i] == 0)
		i++;
	if (i == total_len)
		_putchar('0');
	else
	{
		for (; i < total_len; i++)
			_putchar(result[i] + '0');
	}
	_putchar('\n');
	free(result);
	return (0);
}
