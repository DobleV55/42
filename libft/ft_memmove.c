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

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const void	*source;
	void		*dest;
	void 		*dst_cpy;

	if (dst == NULL && src == NULL)
		return (NULL);
	source = src;
	dest = dst;
	dst_cpy = dst;
	while (len > 0)
	{
		source++;
		dest++;
		len--;
	}
	while (src != source)
	{
		if (src < dst)
		{
			dest--;
			source--;
			*(char *)dest = *(char *)source;
		}
		else
		{
			*(char *)dst = *(char *)src;
			dst++;
			src++;
		}
	}
	return (dst_cpy);
}
