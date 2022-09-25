/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <vvila@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:06:35 by vvila             #+#    #+#             */
/*   Updated: 2022/09/19 00:06:35 by vvila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*s)
	{
		if (*s == (char)(c & 0xff))
			str = (char *)s;
		s++;
	}
	if ((char)(c & 0xff) == '\0' && *s == '\0')
		return ((char *)s);
	if (*str == (char)(c & 0xff) || (char)(c & 0xff) == 0)
		return (str);
	return (NULL);
}
