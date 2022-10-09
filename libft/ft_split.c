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

static void	clean_all(struct s_norm *norm, char **r)
{
	free(norm -> malloc_validator);
	while (*r)
	{
		free(*r);
		r++;
	}
	free(r);
	free(norm);
}

static int	arrays_needed(char const *s, char c)
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
			start = 0;
		s++;
	}
	return (arrays + 1);
}

static void	array_length(char const *s, char c, char **res, struct s_norm *norm)
{
	while (norm -> counter != norm -> arrays_need - 1)
	{
		if (!*s && norm -> array_len)
		{
			norm -> malloc_validator = (char *) malloc (norm -> array_len + 1);
			if (!norm -> malloc_validator)
				return (clean_all(norm, res));
			res[norm -> counter++] = norm -> malloc_validator;
			norm -> array_len = 0;
		}
		else if (*s != c)
			norm -> array_len++;
		else if (*s == c && norm -> array_len)
		{
			norm -> malloc_validator = (char *) malloc (norm -> array_len + 1);
			if (!norm -> malloc_validator)
				return (clean_all(norm, res));
			res[norm -> counter++] = norm -> malloc_validator;
			norm -> array_len = 0;
		}
		s++;
	}
	res[norm -> counter] = NULL;
	return ;
}

static void	place_chars(char const *s, char c, char **res, struct s_norm *norm)
{
	norm -> counter = 0;
	while (norm -> counter != norm -> arrays_need - 1)
	{
		if (*s != c && *s != '\0')
		{
			res[norm -> counter][norm -> j++] = *s;
			norm -> len = 1;
		}
		else if (*s == c && norm -> len)
		{
			res[norm -> counter][norm -> j] = '\0';
			norm -> counter++;
			norm -> j = 0;
			norm -> len = 0;
		}
		else if (*s == '\0')
		{
			res[norm -> counter][norm -> j] = '\0';
			return ;
		}
		s++;
	}
	return ;
}

char	**ft_split(char const *s, char c)
{
	char			**r;
	struct s_norm	*norm;

	if (!s)
		return (NULL);
	norm = malloc(sizeof (struct s_norm));
	if (!norm)
		return (NULL);
	norm -> counter = 0;
	norm -> array_len = 0;
	norm -> j = 0;
	norm -> len = 0;
	norm -> arrays_need = arrays_needed (s, c);
	r = (char **) malloc ((norm->arrays_need) * sizeof(char *));
	if (!r)
	{
		clean_all(norm, r);
		return (r);
	}
	array_length (s, c, r, norm);
	place_chars(s, c, r, norm);
	free(norm);
	return (r);
}
