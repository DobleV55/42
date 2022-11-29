#include "get_next_line.h"

char	*get_before_newline_char(const char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	res = ft_malloc_zero(i + 1, sizeof * res);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}
char	*get_after_newline_char(const char *s)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	while (s && s[j])
		j++;
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	res = ft_malloc_zero((j - i) + 1, sizeof * res);
	if (!res)
		return (NULL);
	j = 0;
	while (s[i + j])
	{
		res[j] = s[i + j];
		j++;
	}
	return (res);
}

char	*ft_reasign_backup(char **backup, char **tmp)
{
	char	*response;

//	printf("backup: %s\n", *backup);
	// leave the chars before the \n in response
//	printf("res: %s.\n", *response);
	*tmp = ft_strdup(*backup);
	ft_free_all(NULL, backup, NULL);
	*backup = get_after_newline_char(*tmp);
	response = get_before_newline_char(*tmp);
//	while ((*tmp)[counter] != '\n' && (*tmp)[counter] != '\0')
//		counter++;
//
//	if ((*tmp)[counter] != '\0')
//		counter++;
//	printf("------response------\n");
//	response = ft_strodup(*tmp, 0, counter);
//	printf("response: %s\n", *response);
//	printf("------finish response-----\n");
	//if (!*response)
	//	return ;
//	printf("------backup------\n");
//	*backup = ft_strodup(*tmp, counter, 0);
//	printf("backup: %s\n", *backup);
//	printf("------finish backup-----\n");
	//if (!*backup)
	//	return ;
	ft_free_all(tmp, NULL, NULL);
	return (response);

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
		*tmp = ft_strdup(*backup);
		ft_free_all(NULL, backup, NULL);
		*backup = ft_strjoin(*tmp, buffer);
		ft_free_all(tmp, NULL, NULL);
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
		response = ft_reasign_backup(&backup, &tmp);
	if (!response || *response == '\0')
	{
		ft_free_all(&tmp, &backup, &response);
		return (NULL);
	}
	return (response);
}
