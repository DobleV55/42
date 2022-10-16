#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*str_cpy;
	int		len;

	len = 0;
	while (*s1)
	{
		s1++;
		len++;
	}
	str_cpy = (char *) malloc (len + 1);
	if (!str_cpy)
		return (0);
	s1 = s1 - len;
	while (*s1)
	{
		*str_cpy = *s1;
		str_cpy++;
		s1++;
	}
	*str_cpy = '\0';
	return (str_cpy - len);
}

static	int	int_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
static	unsigned int	uint_len(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len_n;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len_n = int_len(n);
	res = (char *) malloc (len_n + 1);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		res[0] = '-';
	}
	res[len_n--] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[len_n--] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}
char	*ft_uitoa(unsigned int n)
{
	char	*res;
	unsigned int		len_n;

	if (n == 2147483648)
		return (ft_strdup("2147483648"));
	len_n = uint_len(n);
	res = (char *) malloc (len_n + 1);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		res[0] = '-';
	}
	res[len_n--] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[len_n--] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}


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
int	ft_putstr(char *s, int order)
{
	int	i;

	if (order == -1)
		i = ft_strlen(s) - 1;
	else
		i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i+=(1*order);
	}
	return (ft_strlen(s));
}

int	ft_putnbr(int num)
{
	char	*n;
	int		len_num;

	n = ft_itoa(num);
	ft_putstr(n, 1);
	len_num = strlen(n);
	if (n)
		free(n);
	return (len_num);
}

int	ft_putunbr(unsigned int num)
{
	char	*n;
	int		len_num;

	n = ft_uitoa(num);
	ft_putstr(n, 1);
	len_num = ft_strlen(n);
	if (n)
		free(n);
	return (len_num);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n > 0)
	{
		*str = 0;
		str++;
		n--;
	}
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	r = (void *) malloc (count * size);
	if (!r)
		return (NULL);
	ft_bzero(r, count * size);
	return (r);
}
int	ft_puthexnbr_upper(unsigned int num)
{
	int			temp;
	int			i;
	char 		*hex_num;

	if (!num)
		return (ft_putstr("0", 1));
	hex_num = ft_calloc(1,9);
	i = 0;
	while (num > 0)
	{
		temp = num % 16;
		if (temp < 10)
			hex_num[i++] = temp + 48;
		else
			hex_num[i++] = temp + 55;
		num = num / 16;
	}
	ft_putstr(hex_num, -1);
	free(hex_num);
	return (i);
}

int	ft_puthexnbr_lower(unsigned int num)
{
	int			temp;
	int			i;
	char 		*hex_num;

	if (!num)
		return (ft_putstr("0", 1));
	hex_num = ft_calloc(1,9);
	i = 0;
	while (num > 0)
	{
		temp = num % 16;
		if (temp < 10)
			hex_num[i++] = temp + 48;
		else
			hex_num[i++] = temp + 87;
		num = num / 16;
	}
	ft_putstr(hex_num, -1);
	free(hex_num);
	return (i);
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
		prints += ft_putstr(va_arg(*ap, char*), 1);
	}
	else if (str == 'i' || str == 'd')
	{
		prints += ft_putnbr(va_arg(*ap, int));
	}

	else if (str == 'p')
	{
		write(1, "0x", 2);
		prints += 2;
		prints += ft_putaddress(va_arg(*ap, unsigned long long));
	}
	else if (str == 'u')
		prints += ft_putunbr(va_arg(*ap, unsigned int));
	else if (str == 'x')
		prints += ft_puthexnbr_lower(va_arg(*ap, int));
	else if (str == 'X')
		prints += ft_puthexnbr_upper(va_arg(*ap, int));
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
