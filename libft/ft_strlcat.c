/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <vvila@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:06:35 by vvila             #+#    #+#             */
/*   Updated: 2022/10/13 19:25:07 by valenvila        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_total;
	size_t	len_src;

	if (!dst && (!src || !dstsize))
		return (0);
	len_total = ft_strlen(src) + ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= ft_strlen(dst))
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
	*(dst) = 0;
	return (len_total);
}
