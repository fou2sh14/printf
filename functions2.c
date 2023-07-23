#include "main.h"


/**
 * print_pointer - dflkn kdfndfnhkdfh  dh
 * @types: dfklgndfkg df
 * @buffer: fdkjg fgjdfgjdf gdf
 * @flags:  ljsgnd fgjldfg djfg df g
 * @width: djfkgd fgjldfgdf kfn
 * @precision: dfklhndf hdfnhd hdf h
 * @size: dfjlbndfljnhd dfknkdfhn
 * Return: dghdfh fdhdfhdfhd
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_ch = 0, padding = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (flags & F_PLUS)
		extra_ch = '+', length++;
	else if (flags & F_SPACE)
		extra_ch = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padding, extra_ch, padd_start));
}


/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: fsgsfgsfjgns fgjfsgs gs g
 * @buffer: sfgsfgnfg sjfg sfjgs fg
 * @flags:  sfgsfg sgsgsfgsfgsg
 * @width: sgfsfgsfg sdgsdgsgtsdfsssdsg
 * @precision: fgfs sgfdgfdgdfg gs
 * @size: fgs sdgsfdgsfgsg
 * Return: Nufgfgfgfg dfbdfbfdfdh df
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int f = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[f] != '\0')
	{
		if (is_printable(str[f]))
			buffer[f + offset] = str[f];
		else
			offset += append_hexa_code(str[f], buffer, f + offset);

		f++;
	}

	buffer[f + offset] = '\0';

	return (write(1, buffer, f + offset));
}

/**
 * print_reverse - Prints reverse string.
 * @types: L kngkrng dfgkndfkgndf dfkh
 * @buffer: dfklgndf dkfgndfkgndf gkdfgn
 * @flags:  dlfjgfgnjdfg dfkgndfkgnd fgknf
 * @width: kfdgdfkg kdfn dkfgnn
 * @precision: dlkghb dkdfngd fkdfng
 * @size: dfklgndfg dkfgndfkng dfg
 * Return: Nudfdgkndfkg dfgkndfkgn
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int f, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = "(Null)";
	}
	for (f = 0; str[f]; f++)
		;

	for (f = f - 1; f >= 0; f--)
	{
		char z = str[f];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string in rot13.
 * @types: dfklngkdfngdfkng dfndfkn df,fdn
 * @buffer: dkfngkdfng mdfndfklndf ldfn
 * @flags:  lkfdnglkdfg flkgndfklngdf hln
 * @width: dlkfglkdfg dfklhndfklhndf
 * @precision: Precision specification
 * @size: Ssjgsg fkngsfkng skfgnskgn
 * Return: Nsklfng kdfngd fgdfkgndf gfdgnskf
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int f, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (f = 0; str[f]; f++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[f])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[f];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
