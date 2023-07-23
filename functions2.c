#include "main.h"

/**
 * print_pointer - lkdfnkfn ksdnvksf sdnvsdn
 * @sort: kdnkds sdkfnsdkfn kdfnksdfn
 * @buf: sldm sdfmsfms gksdn
 * @flag:  skngf skgnskfs ksdng kdgs
 * @wid: smdfvn sdkvnksdn sdgkn
 * @per: ksdnsjdfbsd fsdf jsdfbsdb sdgjb
 * @size: sdmn sdnf sdf sdnf
 * Return: osdn sdfnsd fsdkfn
 */
int print_pointer(va_list sort, char buf[],
	int flag, int wid, int per, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(sort, void *);

	UNUSED(wid);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(per);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buf[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';
	if (flag & F_PLUS)
		extra_c = '+', length++;
	else if (flag & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buf[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buf, ind, length,
		wid, flag, padd, extra_c, padd_start));
}

/**
 * print_non_printable - ksdg sdkfn sdfk sjdf sdjfsjdf
 * @sort: sdnfksdnf ksdfn kdnf
 * @buf: skdfn sfbsd f jdsfb df gsdf
 * @flag:  fdga sdgfds sdgfdg sfgs
 * @wid: sdfsdfdsf dsgsd sdgsdgsdg
 * @per: dsgsd sdgsdgsd sgsd
 * @size: sdgsd sd sdgsdg sdg
 * Return: sd sdsdgsd sdgsdgsdg
 */
int print_non_printable(va_list sort, char buf[],
	int flag, int wid, int per, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(sort, char *);

	UNUSED(flag);
	UNUSED(wid);
	UNUSED(per);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buf[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buf, i + offset);

		i++;
	}

	buf[i + offset] = '\0';

	return (write(1, buf, i + offset));
}
/**
 * print_reverse - Prints reverse string.
 * @sort: sdj sdfjsd sjd  sdjng
 * @buf: fsg sdgsdg sdgsg
 * @flag:  Casfd sdesdsd  sdgsdlags
 * @wid: sfg sdsdf df
 * @per: ds fsd v ssfsgcsidssdn  sdvsdg
 * @size: df dfa gsdgdsds sdsf
 * Return:  sdg adfasdsdg  dssdsdf dg
 */

int print_reverse(va_list sort, char buf[],
	int flag, int wid, int per, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buf);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(size);

	str = va_arg(sort, char *);

	if (str == NULL)
	{
		UNUSED(per);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - sdg dgsdgsdgsdg sdgs egsdg
 * @sort:  dsg sgsdgg segsdgsdg
 * @buf: Buffer array to handle print
 * @flag:  sdsdg sdgsdgsdggs
 * @wid: sdgsdg dsfsdgsdg dssdg
 * @per:  dffsdsdgd  sdgsdgsdg
 * @size: ds dsggedgsdg
 * Return: gsd sdg sdg  gsdg
 */
int print_rot13string(va_list sort, char buf[],
	int flag, int wid, int per, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(sort, char *);
	UNUSED(buf);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(per);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
