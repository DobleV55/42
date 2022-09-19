/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <vvila@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:06:34 by vvila             #+#    #+#             */
/*   Updated: 2022/09/19 00:06:34 by vvila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	counter;
	char	*dest;
	char	*source;

	dest = (char *) dst;
	source = (char *) src;
	counter = 0;
	while (counter < len)
	{
		*dest = *source;
		dest++;
		source++;
		counter++;
	}
	*dest = '\0';
	return (dst);
}
