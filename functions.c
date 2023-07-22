#include "main.h"

/**
* print_ch - prints char
* @sort : arg list
* @buf : buffer to handel print
* @flag : good ffkfjgmdk
* @wid : ofnopjgddf slfmlsfm
* @per : ffefef dkmsfls dkenfkfn
* @size : ldfjdfodjflldf dfndlmf dfn
* Return : oodo dlfmdlfm
*/

int print_ch(va_list sort, char buf[],
	int flag, int wid, int per, int size)
{
	char c = va_arg(sort, int);

	return (handle_write_char(c, buf, flag, wid, per, size));
}

/**
 * print_str - sdkgnksdng
 * @sort: dfsd dgfsdf fsdgsdg f df
 * @buf: dfkgkdf skgskdjg sdgjskgj
 * @flag: sdmslkmdgskgm kdsnksdn dksg ksdgn
 * @wid: sdjnsjd dshdsjhgjsd dsjdjsg
 * @per: sdkfjsdkg sdjgsdjg sdgjsdogjso
 * @size: kfd skdgnsdkg sdkgksdgns sdgkn
 * Return: rglndfkg dfklgnfkgn flkgndflkng
 */
int print_str(va_list sort, char buf[],
	int flag, int wid, int per, int size)
{
	int length = 0, i;
	char *str = va_arg(sort, char *);

	UNUSED(buf);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(per);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (per >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (per >= 0 && per < length)
		length = per;

	if (wid > length)
	{
		if (flag & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = wid - length; i > 0; i--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (i = wid - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (wid);
		}
	}

	return (write(1, str, length));
}

/**
 * print_percent - odfo fgngkg nfknfg
 * @sort: fgkdg fdg fgm fgfkg
 * @buf: dflgmg fdgmldfmgldf  dflmgdfg
 * @flag:  kfdgnkdf kfgnkdfng dfngkk
 * @wid: kdfmdf lfddlfg.
 * @per: sflgmslg skgmlsmg
 * @size: sdmfksf skfmsdkfn kdsfnksdnf
 * Return: Number of chars printed
 */
int print_percent(va_list sort, char buf[],
	int flag, int wid, int per, int size)
{
	UNUSED(sort);
	UNUSED(buf);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(per);
	UNUSED(size);
	return (write(1, "%%", 1));
}


/**
 * print_int - Print int
 * @sort: kdsg ksgnksgn ksgnksg
 * @buf: sdmsd sdgms;dkmng fdmgkdfgm
 * @flag:  smfksdmlsd lsdgmlsdg lsdmg
 * @wid: ksdnk skdnksdng
 * @per: dslksd skdsdklns ddlsmg
 * @size: lsdmgl ksdnksdng
 * Return: sdkfnsdkgnsdng skfngs
 */
int print_int(va_list sort, char buf[],
	int flag, int wid, int per, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(sort, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buf[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buf, flag, wid, per, size));
}

/**
 * print_binary - sdfls sdlgmsdlgm lmdglmdgs
 * @sort: ksdgnksdgn sdkgnkdgn
 * @buf: Bfgsfgsg sdsdgsdg sdgg
 * @flag:  dsf dfsdg ddsgsdg
 * @wid: fgsg sdfsdgg dgsdgs
 * @per: sgsdg dfsdgg dssdg
 * @size: dg dgdsgsd dsdgsdgsg
 * Return: sdgsdg sdgsdg dsdgg
 */
int print_binary(va_list sort, char buf[],
	int flag, int wid, int per, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buf);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(per);
	UNUSED(size);

	n = va_arg(sort, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
