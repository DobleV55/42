#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list ap;
	int i;
	size_t args;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && *(str+1) == 's')
		{
			char *s;
			s = va_arg(ap, char*);
			while (*s)
			{
				write(1, s, 1);
				s++;
			}
			str++;
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
	va_end(ap);
	return (0);
}
