/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <vvila@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:06:35 by vvila             #+#    #+#             */
/*   Updated: 2022/09/19 00:06:35 by vvila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		str++;
	}
	str--;
	while (*str)
	{
		if (*str == (char) c)
		{
			return (str);
		}
		str--;
	}
	return (0);
}
