/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <vvila@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:06:35 by vvila             #+#    #+#             */
/*   Updated: 2022/09/19 00:06:35 by vvila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	counter;
	size_t	len_src;

	counter = 0;
	len_src = 0;
	while (counter < dstsize - 1)
	{
		*dst = *src;
		dst++;
		src++;
		counter++;
	}
	*dst = '\0';
	return (len_src);
}
