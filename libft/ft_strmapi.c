/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <vvila@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:06:35 by vvila             #+#    #+#             */
/*   Updated: 2022/09/19 00:06:35 by vvila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		count;
	char	*res;

	res = (char *) malloc (ft_strlen(s));
	count = 0;
	while (s[count])
	{
		res[count] = f(count, s[count]);
		count++;
	}
	return (res);
}
