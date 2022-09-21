/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <vvila@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:06:35 by vvila             #+#    #+#             */
/*   Updated: 2022/09/19 00:06:35 by vvila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	len_total;
	size_t	len_src;

	len_total = ft_strlen(src) + ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= ft_strlen(dst))
		return (len_src + dstsize);
	if (dstsize == 0)
		return (len_src + dstsize);
	while (*dst != 0)
	{
		dst++;
		dstsize--;
	}
	while (*src != 0 && dstsize > 1)
	{
		*dst = *src;
		src++;
		dst++;
		dstsize--;
	}
	*(dst++) = 0;
	return (len_total);
}
