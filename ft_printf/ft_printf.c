/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valenvila <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:58:46 by valenvila         #+#    #+#             */
/*   Updated: 2022/10/20 15:59:15 by valenvila        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	char	*n;
	int		len_num;

	n = ft_itoa(num);
	ft_putstr(n, 1);
	len_num = ft_strlen(n);
	if (n)
		free(n);
	return (len_num);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_format(va_list *ap, const char str)
{
	int	prints;

	prints = 0;
	if (str == 'c')
		prints += ft_putchar(va_arg(*ap, int));
	else if (str == 's')
		prints += ft_putstr(va_arg(*ap, *char), 1);
	else if (str == 'i' || str == 'd')
		prints += ft_putnbr(va_arg(*ap, int));
	else if (str == 'p')
	{
		prints += write(1, "0x", 2);
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

int	ft_printf(const char *str, ...)
{
	int		i;
	int		prints;
	va_list	ap;

	i = 0;
	prints = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			prints += ft_format(&ap, str[i + 1]);
			i++;
		}
		else
			prints += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (prints);
}
