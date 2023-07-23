#include "main.h"

/**
 * is_printable - sksdmssmfns vksdf sdgk sdkg
 * @c: khrf sfksg fsgkfdgfgnfg fkdgn
 *
 * Return: 1 if sfnkkfdgn f ,sng is prisfdgsf
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append asccodifhg dfjgbdfg dfjogdfkjgdfog
 * @buffer: jsdhf sdmfnsd fsdfn
 * @i: sjdlh sdmflshdf smdlf
 * @ascii_code: dkfg dfgh mfvng
 * Return: sdjfh sdjfh
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Vpisjgr sgnd fgbdfjgbd fj
 * @c: jfdhg dfmgdfgifg
 *
 * Return: 1 if c fkgndfg dfkngd fgnkdfkgn
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - fsig fskg fsksfhg smfgkkfg
 * @num: fshgd fgljdg ,drgj
 * @size: skdhg sfmgkf gdkgfsk gfkj
 *
 * Return: ksfhg sfmgkhf gkfg
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - sfhgsf mgnhfsg jsfghjf g
 * @num: dfkg dfgkjdfg kdfgj
 * @size: fshgd fkgdfg fdkgn
 *
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
