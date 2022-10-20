/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valenvila <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:59:14 by valenvila         #+#    #+#             */
/*   Updated: 2022/10/20 15:59:14 by valenvila        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_strdup(const char *s1)
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

static	unsigned	int	uint_len(unsigned int n)
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
	unsigned int		len_n;
	char				*res;

	if (n == 2147483648)
		return (ft_strdup("2147483648"));
	len_n = uint_len(n);
	res = (char *) malloc (len_n + 1);
	if (!res)
		return (NULL);
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
