#include "ft_printf.h"

void	norm_putchar(char c)
{
	write (1, &c, 1);
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
	if (!num)
		return (1);
	if (num < 0)
	{
		norm_putchar('-');
		num = num * -1;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		norm_putchar(num + '0');
	return (1);
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

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_puthexnbr(int num, char format)
{

	char	*hexchar_lower;
	char	*hexchar_upper;

	hexchar_lower = "0123456789abcdef";
	hexchar_upper = "0123456789ABCDEF";
	if (num >= 16)
	{
		ft_puthexnbr(num / 16, format);
		ft_puthexnbr(num % 16, format);
	}
	else if (format == 'x')
		norm_putchar(hexchar_lower[num % 16]);
	else
		norm_putchar(hexchar_upper[num % 16]);
	return (1);
}

int	ft_putaddress(unsigned long num)
{

	char	*hexchar;

	hexchar = "0123456789abcdef";
	if (num >= 16)
	{
		ft_putaddress(num / 16);
		ft_putaddress(num % 16);
	}
	else
		norm_putchar(hexchar[num % 16]);
	return (1);
}

int	ft_format(va_list ap, const char str)
{
	int	prints;

	prints = 0;
	if (str == 'i' || str == 'd')
		prints += ft_putnbr(va_arg(ap, int));
	else if (str == 'p')
	{
		norm_putchar('0');
		norm_putchar('x');
		prints += 2;
		prints += ft_putaddress(va_arg(ap, unsigned long long));
	}
	else if (str == 'u')
		prints += ft_putnbr(va_arg(ap, unsigned int));
	else if (str == 'x' || str == 'X')
		prints += ft_puthexnbr(va_arg(ap, int), str);
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
		if (str[i] == '%' && str[i+1] == 'c')
		{
			prints += ft_putchar(va_arg(ap, int));
			i++;
		}
		else if (str[i] == '%' && str[i+1] == 's')
		{
			prints += ft_putstr(va_arg(ap, char*));
			i++;
		}
		else if (str[i] == '%')
		{
			prints += ft_format(ap, str[i+1]);
			i++;
		}
		else
			prints += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (prints);
}
