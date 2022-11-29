#include "get_next_line.h"

void	map_response_and_backup(char *tmp, char **response, char **backup)
{
	char	*res;
	char	*back;
	int		i;
	int		j;

	tmp = ft_strdup(*backup);
	ft_free_all(NULL, backup, NULL);
	i = 0;
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	res = ft_calloc(i + 1, 1);
	if (!res)
		return ;
	i = 0;
	while (tmp[i] != '\0' && tmp[i] != '\n')
	{
		res[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		res[i] = '\n';
	*response = res;

	j = 0;
	while (tmp && tmp[j])
		j++;
	i = 0;
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	back = ft_calloc((j - i) + 1, 1);
	if (!back)
		return ;
	j = 0;
	while (tmp[i + j])
	{
		back[j] = tmp[i + j];
		j++;
	}
	*backup = back;
	ft_free_all(&tmp, NULL, NULL);
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

void	ft_read_file(int fd, char **backup, char **tmp)
{
	int 		chars_read;
	char		*buffer;

	chars_read = 1;
	buffer = (char *) malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	while(chars_read > 0)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read < 0)
		{
			ft_free_all(&buffer, backup, tmp);
			return ;
		}
		buffer[chars_read] = '\0';
		// copio backup en tmp
		*tmp = ft_strdup(*backup);
		// libero backup
		ft_free_all(NULL, backup, NULL);
		// backup -> tmp + buffer
		*backup = ft_strjoin(*tmp, buffer);
		// libero tmp
		ft_free_all(tmp, NULL, NULL);
		// se podria hacer: buffer = buffer + backup -> libero backup -> backup = buffer -> libero buffer (o no :c)
		// buffer = ft_strjoin(*backup, buffer);
		// ft_free_all(NULL, backup, NULL);
		// *backup = ft_strdup(buffer);
		// ft_free_all(&buffer, NULL, NULL);
		if (ft_get_new_line_char_position(*backup) != 0)
			break ;
	}
	ft_free_all(&buffer, NULL, NULL);
}

char	*get_next_line(int fd)
{
	char static	*backup = NULL;
	char		*response;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	response = NULL;
	tmp = NULL;
	ft_read_file(fd, &backup, &tmp);
	if (backup != NULL && *backup != '\0')
		map_response_and_backup(tmp, &response, &backup);
	if (!response || *response == '\0')
	{
		ft_free_all(&tmp, &backup, &response);
		return (NULL);
	}
	return (response);
}
