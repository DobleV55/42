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
	size_t		len_s;
	char		*r;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s)
	{
		r = (char *) malloc(1);
		*r = '\0';
		return (r);
	}
	if (len_s - start < len)
		len = len_s - start;
	r = (char *) malloc (len + 1);
	if (!r)
		return (NULL);
	if (len_s > start)
		ft_strlcpy(r, (s + start), (len + 1));
	return (r);
}
