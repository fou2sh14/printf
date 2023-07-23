#include "main.h"

/**
 * get_flags - get the flags
 * @format: the format
 * @i: paramater
 * Return: int
 */

int get_flags(const char *format, int *i)
{
	int g, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (g = 0; FLAGS_CH[g] != '\0'; g++)
			if (format[curr_i] == FLAGS_CH[g])
			{
				flags |= FLAGS_ARR[g];
				break;
			}

		if (FLAGS_CH[g] == 0)
		{
			break;
		}
	}
	*i = curr_i - 1;

	return (flags);
}
