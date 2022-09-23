/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <vvila@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:06:34 by vvila             #+#    #+#             */
/*   Updated: 2022/09/19 00:06:34 by vvila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	n;

	sign = 1;
	n = 0;
	while (*str == ' ' || *str == 9 || *str == 10 || *str == 11
		|| *str == 12 || *str == 13)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
		if (*str == '-' || *str == '+')
			return (n);
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - 48);
		str++;
	}
	if (n > 2147483648 && sign == -1)
		return (0);
	else if (n > 2147483648 && sign == 1)
		return (-1);
	return (n * sign);
}
