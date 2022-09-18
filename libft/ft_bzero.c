/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <vvila@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:04:55 by vvila             #+#    #+#             */
/*   Updated: 2022/09/19 00:06:34 by vvila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_bzero(void *s, size_t len)
{
	size_t	counter;
	char	*str;

	str = s;
	counter = 0;
	while (counter < len)
	{
		str[counter] = '\0';
		str++;
		counter++;
	}
	return (0);
}
