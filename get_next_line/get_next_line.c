/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valenvila <vvila@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:59:14 by valenvila         #+#    #+#             */
/*   Updated: 2022/10/20 15:59:14 by valenvila        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

void	map_response_and_backup(char **response, char **backup)
{
	int		i;
	char	*res;
	char	*back;

	i = 0;
	while ((*backup)[i] && (*backup)[i] != '\n')
		i++;
	res = ft_substr(*backup, 0, i + ((*backup)[i] == '\n'));
	if (!res)
		return ;
	*response = res;
	back = ft_strdup(*backup + i + ((*backup)[i] == '\n'));
	ft_free_all(NULL, backup, NULL);
	*backup = back;
}

void	ft_free_all(char **buffer, char **backup, char **response)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if (backup && *backup)
	{
		free(*backup);
		*backup = NULL;
	}
	if (response && *response)
	{
		free(*response);
		*response = NULL;
	}
}

void	ft_read_file(int fd, char **backup)
{
	int			chars_read;
	char		*buffer;
	char		*tmp;

	chars_read = 1;
	buffer = (char *) malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	while (chars_read > 0)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read < 0)
			return (ft_free_all(&buffer, backup, NULL));
		buffer[chars_read] = '\0';
		tmp = ft_strdup(*backup);
		ft_free_all(NULL, backup, NULL);
		*backup = ft_strjoin(tmp, buffer);
		ft_free_all(&tmp, NULL, NULL);
		if (ft_get_new_line_char_position(*backup) != 0)
			break ;
	}
	ft_free_all(&buffer, NULL, NULL);
}

char	*get_next_line(int fd)
{
	char static	*backup = NULL;
	char		*response;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	response = NULL;
	ft_read_file(fd, &backup);
	if (backup != NULL && *backup != '\0')
		map_response_and_backup(&response, &backup);
	if (!response || *response == '\0')
	{
		ft_free_all(NULL, &backup, &response);
		return (NULL);
	}
	return (response);
}
