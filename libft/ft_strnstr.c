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

int	validate_found(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*haystack != *needle)
		{
			return (0);
		}
		haystack++;
		needle++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	counter;

	counter = 0;
	while (haystack[counter] && counter < len)
	{
		if (haystack[counter] == needle[0])
		{
			if (validate_found(&haystack[counter], needle) == 1)
			{
				return ((char *)(&haystack[counter]));
			}
		}
		counter++;
	}
	return ((char *)(haystack));
}
