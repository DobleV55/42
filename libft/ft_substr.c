/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <vvila@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:06:35 by vvila             #+#    #+#             */
/*   Updated: 2022/09/19 00:06:35 by vvila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*r;
	char		*r_cpy;

	if (start >= ft_strlen(s) || start == 4294967295)
	{
		r = (char *) ft_calloc (1, 1);
		if (!r)
			return (NULL);
		return (r);
	}
	if (len > ft_strlen(s))
		r = (char *) malloc ((ft_strlen(s) - start) + 1);
	else
		r = (char *) malloc (len + 1);
	if (!r)
		return (NULL);
	r_cpy = r;
	s = s + start;
	while (*s && len)
	{
		*r++ = *s++;
		len--;
	}
	*r = '\0';
	return (r_cpy);
}
