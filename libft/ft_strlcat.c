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

#include <string.h>

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	len_dst;

	len_dst = 0;
	while (*dst)
	{
		dst++;
		len_dst++;
	}
	while (len_dst < dstsize - 1)
	{
		*dst = *src;
		dst++;
		src++;
		len_dst++;
	}
	*dst = '\0';
	return (len_dst);
}
