/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <vvila@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:06:35 by vvila             #+#    #+#             */
/*   Updated: 2022/09/19 00:06:35 by vvila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	char_in_set(char const *c, char const *set)
{
	while (*set)
	{
		if (*set == *c)
			return (1);
		set++;
	}
	return (0);
}

char	*normi_right_pointer(char const *s1, char const *set)
{
	char	*right_index;

	right_index = (char *) s1 + ft_strlen(s1) - 1;
	while (char_in_set(right_index, set))
		right_index--;
	return (right_index);
}

char	*normi_left_pointer(char const *s1, char const *set)
{
	char	*left_index;

	left_index = (char *) s1;
	while (char_in_set(left_index, set))
		left_index++;
	return (left_index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*left_index;
	char	*right_index;
	char	*r;
	int		len_r;

	if (!s1 || !set)
		return (NULL);
	left_index = normi_left_pointer(s1, set);
	right_index = normi_right_pointer(s1, set);
	len_r = right_index - left_index + 1;
	if (right_index - left_index <= 0 || !*s1 || !*set)
		return (ft_calloc(1, 1));
	r = (char *) malloc (right_index - left_index + 2);
	if (!r)
		return (NULL);
	while (left_index <= right_index)
	{
		*r = *left_index;
		left_index++;
		r++;
	}
	*r = '\0';
	return (r - len_r);
}
