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
	size_t		i;
	size_t		r_size;
	char		*r;

	i = 0;
	while ((s[i] != (char)start) && (i < len && s[i]))
		i++;
	//printf("%s", &s[i]);
	r = (char *) malloc (i);
	r_size = len - i;
	while (i < len)
	{
		*r = s[i];
		i++;
		r++;
	}
	//printf("%s", r - r_size);
	return (r - r_size);
}
