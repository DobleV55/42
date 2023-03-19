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

void	map_response_and_backup(char **response, char **backup)
{
	char	*res;
	char	*back;
	int		i;
	int		j;

	i = 0;
	while ((*backup)[i] != '\0' && (*backup)[i] != '\n')
		i++;
	if ((*backup)[i] == '\n')
		i++;
	res = ft_calloc(i + 1, 1);
	if (!res)
		return ;
	i = 0;
	while ((*backup)[i] != '\0' && (*backup)[i] != '\n')
	{
		res[i] = (*backup)[i];
		i++;
	}
	if ((*backup)[i] == '\n')
		res[i] = '\n';
	*response = res;
	j = 0;
	while (*backup && (*backup)[j])
		j++;
	i = 0;
	while ((*backup)[i] != '\0' && (*backup)[i] != '\n')
		i++;
	if ((*backup)[i] == '\n')
		i++;
	back = ft_calloc((j - i) + 1, 1);
	if (!back)
		return ;
	j = 0;
	while ((*backup)[i + j])
	{
		back[j] = (*backup)[i + j];
		j++;
	}
	ft_free_all(NULL, backup, NULL);
	*backup = back;
	return ;
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
