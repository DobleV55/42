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


static void	clean_all(struct NormiSplit *norm, char **r)
{
	free(norm -> malloc_validator);
	while (*r)
	{
		free(*r);
		r++;
	}
	free(r);
	free(norm);
	exit(1);
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

static void	array_length(char const *s, char c, char **res, struct NormiSplit *norm)
{
	while (norm -> counter != norm -> arrays_need - 1)
	{
		if (!*s && norm -> array_len)
		{
			norm -> malloc_validator = (char *) malloc (norm -> array_len + 1);
			if (!norm -> malloc_validator)
				return clean_all(norm, res);
			res[norm -> counter++] = norm -> malloc_validator;
			norm -> array_len = 0;
		}
		else if (*s != c)
			norm -> array_len++;
		else if (*s == c && norm -> array_len)
		{
			norm -> malloc_validator = (char *) malloc (norm -> array_len + 1); //TODO: Verificar que malloc (array_len) == mallox(sizeof(char *) * array_len)
			if (!norm -> malloc_validator)
				return clean_all(norm, res);
			res[norm -> counter++] = norm -> malloc_validator;
			norm -> array_len = 0;
		}
		s++;
	}
	res[norm -> counter] = NULL;
	return ;
}

static void	place_elements_into_arr(char const *s, char c, char **res, struct NormiSplit *norm)
{
	int	j;
	int	len;

	j = 0;
	len = 0;
	norm -> counter = 0;
	while (norm -> counter != norm -> arrays_need - 1)
	{
		if (*s != c && *s != '\0')
		{
			res[norm -> counter][j++] = *s;
			len = 1;
		}
		else if (*s == c && len)
		{
			res[norm -> counter][j] = '\0';
			norm -> counter++;
			j = 0;
			len = 0;
		}
		else if (*s == '\0')
		{
			res[norm -> counter][j] = '\0';
			return;
		}
		s++;
	}
	return ;
}

char	**ft_split(char const *s, char c)
{
	char				**r;
	struct NormiSplit	*norm;

	if (!s)
		return (NULL);
	norm = malloc(sizeof (struct NormiSplit));
	if (!norm)
		return (NULL);
	norm -> counter = 0;
	norm -> array_len = 0;
	norm -> arrays_need = arrays_needed (s, c);
	r = (char **) malloc ((norm->arrays_need) * sizeof(char *));
	if (!r)
	{
		clean_all(norm, r);
		return (r);
	}
	array_length (s, c, r, norm);
	place_elements_into_arr (s, c, r, norm);
	free(norm);
	return (r);
}
