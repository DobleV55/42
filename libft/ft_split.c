/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <vvila@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:06:35 by vvila             #+#    #+#             */
/*   Updated: 2022/09/19 00:06:35 by vvila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	arrays_needed(char const *s, char c)
{
	int	arrays;
	int	start;

	arrays = 0;
	start = 0;
	while (*s)
	{
		if (*s != c && !start)
		{
			arrays++;
			start = 1;
		}
		else if (*s == c)
		{
			start = 0;
		}
		s++;
	}
	return (arrays);
}

void	array_length(char const *s, char c, char **res, struct NormiSplit *norm)
{
	while (norm -> counter < norm -> arrays_need)
	{
		if (*s == '\0' && norm -> array_len)
		{
			norm -> malloc_validator = (char *) malloc (norm -> array_len);
			if (!norm -> malloc_validator)
				return ;
			res[norm -> counter++] = norm -> malloc_validator;
		}
		else if (*s != c)
			norm -> array_len++;
		else if (*s == c && norm -> array_len)
		{
			norm -> malloc_validator = (char *) malloc (norm -> array_len);
			if (!norm -> malloc_validator)
				return ;
			res[norm -> counter++] = norm -> malloc_validator;
			norm -> array_len = 0;
		}
		s++;
	}
	res[norm -> counter] = NULL;
	return ;
}

void	place_elements_into_arr(char const *s, char c, char **res)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (*s)
	{
		if (*s != c)
		{
			res[i][j++] = *s;
			len++;
		}
		else if (*s == c && len)
		{
			i++;
			j = 0;
			len = 0;
		}
		s++;
	}
	return ;
}

char	**ft_split(char const *s, char c)
{
	char				**r;
	struct NormiSplit	*norm;

	norm = malloc(sizeof (struct NormiSplit));
	if (!norm)
		return (NULL);
	norm -> counter = 0;
	norm -> array_len = 0;
	if (!s)
		return (NULL);
	norm -> arrays_need = arrays_needed (s, c);
	r = (char **) malloc ((norm->arrays_need + 1) * sizeof(char *));
	if (!r)
		return (0);
	array_length (s, c, r, norm);
	place_elements_into_arr (s, c, r);
	return (r);
}
