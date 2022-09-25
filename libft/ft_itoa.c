/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <vvila@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:06:34 by vvila             #+#    #+#             */
/*   Updated: 2022/09/19 00:06:34 by vvila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int_len(int n)
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
	return (len + 1);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len_n;

	len_n = int_len(n);
	res = (char *) malloc (len_n);
	if (!res)
		return (NULL);
	if (n == -2147483648)
	{
		free(res);
		return (ft_strdup("-2147483648"));
	}
	if (n < 0)
	{
		n = n * -1;
		res[0] = '-';
	}
	len_n--;
	res[len_n--] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[len_n] = (n % 10) + '0';
		n = n / 10;
		len_n--;
	}
	return (res);
}
