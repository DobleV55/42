/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lline_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valenvila <vvila@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:59:14 by valenvila         #+#    #+#             */
/*   Updated: 2022/10/20 15:59:14 by valenvila        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*str_cpy;
	int		len;

	len = 0;
	if (!s1)
		return ((char *)ft_calloc(1, 1));
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

char	*ft_strjoin(char	*s1, char const	*s2)
{
	int		len_s1;
	int		len_s2;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = malloc (len_s1 + len_s2 + 1);
	if (!s3)
		return (NULL);
	while (*s1)
	{
		*s3 = *s1;
		s1++;
		s3++;
	}
	while (*s2)
	{
		*s3 = *s2;
		s2++;
		s3++;
	}
	*s3 = '\0';
	return (s3 - (len_s1 + len_s2));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;
	char	*str;
	size_t	n;

	n = (count * size);
	r = (void *) malloc (n);
	if (!r)
		return (NULL);
	str = r;
	while (n > 0)
	{
		*str = 0;
		str++;
		n--;
	}
	return (r);
}

int	ft_get_new_line_char_position(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char) '\n')
			return (i);
		i++;
	}
	return (0);
}
