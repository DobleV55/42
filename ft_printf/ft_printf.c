#include "ft_printf.h"

void	norm_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putuint(unsigned int num)
{
	if (!num)
		return (1);
	if (num >= 10)
	{
		ft_putuint(num / 10);
		ft_putuint(num % 10);
	}
	else
		norm_putchar(num + '0');
	return (1);
}

int	ft_putnbr(int num)
{
	static int	num_len;

	if (num == -2147483648)
		return write(1, "-2147483648", 11);
	if (num < 0)
	{
		num_len = 0;
		num_len += ft_putchar('-');
		num = num * -1;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		num = num % 10;
	}
	num_len += ft_putchar(num + '0');
	return (num_len);
}

int	ft_putunbr(unsigned int num)
{
	static int	num_len;

	if (num == 2147483648)
		return write(1, "2147483648", 10);
	if (num >= 10)
	{
		num_len += ft_putnbr(num / 10);
		num = num % 10;
	}
	num_len += ft_putchar(num + '0');
	return (num_len);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

int	ft_puthexnbr(unsigned int num, char format)
{
	static int	num_len;
	char		*hexchar_lower;
	char		*hexchar_upper;

	hexchar_lower = "0123456789abcdef";
	hexchar_upper = "0123456789ABCDEF";
	if (num >= 16)
	{
		ft_puthexnbr(num / 16, format);
		num = num % 16;
	}
	if (format == 'x')
		num_len += ft_putchar(hexchar_lower[num % 16]);
	else
		num_len += ft_putchar(hexchar_upper[num % 16]);
	return (num_len);
}

int	ft_putaddress(unsigned long num)
{
	static int 	num_len;
	char		*hexchar;

	num_len = 0;
	hexchar = "0123456789abcdef";
	if (num >= 16)
	{
		ft_putaddress(num / 16);
		num = num % 16;
	}
	num_len += ft_putchar(hexchar[num % 16]);
	return (num_len);
}

static int	ft_format(va_list *ap, const char str)
{
	int	prints;

	prints = 0;
	if (str == 'c')
	{
		prints += ft_putchar(va_arg(*ap, int));
	}
	else if (str == 's')
	{
		prints += ft_putstr(va_arg(*ap, char*));
	}
	else if (str == 'i' || str == 'd')
		prints += ft_putnbr(va_arg(*ap, int));
	else if (str == 'p')
	{
		write(1, "0x", 2);
		prints += 2;
		prints += ft_putaddress(va_arg(*ap, unsigned long long));
	}
	else if (str == 'u')
		prints += ft_putunbr(va_arg(*ap, unsigned int));
	else if (str == 'x' || str == 'X')
		prints += ft_puthexnbr(va_arg(*ap, int), str);
	else if (str == '%')
		prints += ft_putchar('%');
	return (prints);
}

int ft_printf(const char *str, ...)
{
	int	i;
	int	prints;
	va_list ap;

	i = 0;
	prints = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			prints += ft_format(&ap, str[i+1]);
			i++;
		}
		else
			prints += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (prints);
}
