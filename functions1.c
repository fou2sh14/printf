#include "main.h"

/**
 * print_unsigned - print a number
 * @types: args
 * @buffer: array of buffers
 * @flags: the flags
 * @width: the width
 * @precision: the percision
 * @size: the length, size
 * Return: int
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int f = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
	{
		buffer[f--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[f--] = (number % 10) + '0';
		number /= 10;
	}
	f++;

	return (write_unsgnd(0, f, buffer, flags, width, precision, size));
}

/**
 * print_octal - print num in octal
 * @types: list of types args
 * @buffer: array of buffers
 * @flags: the flags
 * @width: the width
 * @precision: the percision
 * @size: the size
 * Return: int
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int f = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
	{
		buffer[f--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[f--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & F_HASH && init_number != 0)
	{
		buffer[f--] = '0';
	}
	f++;

	return (write_unsgnd(0, f, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - prints number in hexadecimal
 * @types: args
 * @buffer: array of buffers
 * @flags: the flags
 * @width: the width
 * @precision: the precision
 * @size: the size
 * Return: int
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - print number in upper hexadecimal
 * @types: args
 * @buffer: array of buffers
 * @flags: the flags
 * @width: the width
 * @precision: the precision
 * @size: the size
 * Return: int
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - prints number in hexa upper or lower
 * @types: args
 * @map_to: values to map number
 * @buffer: array of buffers
 * @flags: the flags
 * @flag_ch: calc flags
 * @width: the width
 * @precision: the percision
 * @size: size sep
 * @size: to size sepicification
 * Return: int
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int f = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
	{
		buffer[f--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[f--] = map_to[number % 16];
		number /= 16;
	}
	if (flags & F_HASH && init_number != 0)
	{
		buffer[f--] = flag_ch;
		buffer[f--] = '0';
	}
	f++;

	return (write_unsgnd(0, f, buffer, flags, width, precision, size));
}
