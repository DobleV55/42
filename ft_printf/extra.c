/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valenvila <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:59:14 by valenvila         #+#    #+#             */
/*   Updated: 2022/10/20 15:59:14 by valenvila        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		i += (1 * order);
	}
	return (ft_strlen(s));
}

int	ft_putaddress(unsigned long num)
{
	static int		num_len;
	char			*hexchar;

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

int	ft_puthexnbr_upper(unsigned int num)
{
	int			temp;
	int			i;
	char		*hex_num;

	if (!num)
		return (ft_putstr("0", 1));
	hex_num = ft_calloc(1, 9);
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
	char		*hex_num;

	if (!num)
		return (ft_putstr("0", 1));
	hex_num = ft_calloc(1, 9);
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
