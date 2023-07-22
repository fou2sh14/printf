#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - like printf function in c
 *
 * @format: the format
 *
 * Return: int
 */

int _printf(const char *format, ...)
{
	int f, printed = 0, chars_printed = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list lst;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}

	va_start(lst, format);

	for (f = 0; format && format[f] != '\0'; f++)
	{
		if (format[f] != '%')
		{
			buffer[buff_ind++] = format[f];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
			}
			chars_printed++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &f);
			width = get_width(format, &f, lst);
			precision = get_precision(format, &f, lst);
			size = get_size(format, &f);
			++f;
			printed = handle_print(format, &f, lst, buffer, flags,
					width, precision, size);
			if (printed == -1)
			{
				return (-1);
			}
			chars_printed += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(lst);

	return (chars_printed);
}

/**
 * print_buffer - function to buffer
 *
 * @buffer: the buffer array
 *
 * @buff_ind: index
 *
 * Return: void
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}
	*buff_ind = 0;
}
