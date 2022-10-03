#include "ft_printf.h"

void	norm_putchar(char c)
{
	write (1, &c, 1);
}

char const	*ft_putuint(char const *str, unsigned int num)
{
	if (!num)
		return (++str);
	if (num >= 10)
	{
		ft_putuint(str, num / 10);
		ft_putuint(str, num % 10);
	}
	else
		norm_putchar(num + '0');
	str++;
	return (str);
}

char const	*ft_putnbr(char const *str, int num)
{
	if (!num)
		return (++str);
	if (num < 0)
	{
		norm_putchar('-');
		num = num * -1;
	}
	if (num >= 10)
	{
		ft_putnbr(str, num / 10);
		ft_putnbr(str, num % 10);
	}
	else
		norm_putchar(num + '0');
	str++;
	return (str);
}

char const	*ft_putstr(char const *str, char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	str++;
	return (str);
}

char const	*ft_putchar(char const *str, char c)
{
	write(1, &c, 1);
	str++;
	return (str);
}

char const	*ft_puthexnbr(char const *str, int num, int is_lower) {

	char	*hexchar_lower;
	char	*hexchar_upper;

	hexchar_lower = "0123456789abcdef";
	hexchar_upper = "0123456789ABCDEF";
	if (num >= 16)
	{
		ft_puthexnbr(str, num / 16, is_lower);
		ft_puthexnbr(str, num % 16, is_lower);
	}
	else if (is_lower)
		norm_putchar(hexchar_lower[num % 16]);
	else
		norm_putchar(hexchar_upper[num % 16]);
	str++;
	return (str);
}

char const	*ft_putaddress(char const *str, unsigned long num) {

	char	*hexchar;

	hexchar = "0123456789abcdef";
	if (num >= 16)
	{
		ft_putaddress(str, num / 16);
		ft_putaddress(str, num % 16);
	}
	else
		norm_putchar(hexchar[num % 16]);
	str++;
	return (str);
}

int ft_printf(const char *str, ...)
{
	va_list ap;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && *(str+1) == 's')
			str = ft_putstr(str, va_arg(ap, char*));
		else if (*str == '%' && (*(str+1) == 'i' || *(str+1) == 'd'))
			str = ft_putnbr(str, va_arg(ap, int));
		else if (*str == '%' && *(str+1) == 'c')
			str = ft_putchar(str, va_arg(ap, int));
		else if (*str == '%' && *(str+1) == 'p')
		{
			norm_putchar('0');
			norm_putchar('x');
			str = ft_putaddress(str, va_arg(ap, unsigned long));
		}
		else if (*str == '%' && *(str+1) == 'u')
			str = ft_putnbr(str, va_arg(ap, unsigned int));
		else if (*str == '%' && *(str+1) == 'x')
			str = ft_puthexnbr(str, va_arg(ap, int), 1);
		else if (*str == '%' && *(str+1) == 'X')
			str = ft_puthexnbr(str, va_arg(ap, int), 0);
		else
			write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (0);
}
