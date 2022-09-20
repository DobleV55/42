/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <vvila@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:06:35 by vvila             #+#    #+#             */
/*   Updated: 2022/09/19 00:06:35 by vvila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

int	validate_found(const char *haystack, const char *needle, size_t len)
{
	while (*needle)
	{
		if (*haystack != *needle || len <= 0)
		{
			return (0);
		}
		haystack++;
		needle++;
		len--;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;

	if(!*needle)
		return((char *)haystack);
	idx = 0;
	while (haystack[idx] != '\0' && len > 0)
	{
		if (haystack[idx] == needle[0])
		{
			if (validate_found(&haystack[idx], needle, len) == 1)
			{
				return ((char *)(&haystack[idx]));
			}
		}
		idx++;
		len--;
	}
	return (0);
}
