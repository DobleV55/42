/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <vvila@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:06:35 by vvila             #+#    #+#             */
/*   Updated: 2022/09/19 00:06:35 by vvila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*str_cpy;
	int		len;

	len = 0;
	while (*s1)
	{
		s1++;
		len++;
	}
	str_cpy = (char *) malloc (len + 1);
	if (!str_cpy)
		return (0);
	s1 = s1 - len;
	while (*s1)
	{
		*str_cpy = *s1;
		str_cpy++;
		s1++;
	}
	*str_cpy = '\0';
	return (str_cpy - len);
}
