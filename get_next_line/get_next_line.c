#include "get_next_line.h"

void	ft_reasign_backup(char **backup, char **response)
{
	int counter;

//	printf("backup: %s\n", *backup);
	counter = 0;
	// leave the chars before the \n in response
//	printf("res: %s.\n", *response);
	while ((*backup)[counter] != '\n' && (*backup)[counter] != '\0')
		counter++;

	if ((*backup)[counter] != '\0')
		counter++;
//	printf("------response------\n");
	*response = ft_strodup(*backup, 0, counter);
//	printf("response: %s\n", *response);
//	printf("------finish response-----\n");
	if (!*response)
		return ;
//	printf("------backup------\n");
	*backup = ft_strodup(*backup, counter, 0);
//	printf("backup: %s\n", *backup);
//	printf("------finish backup-----\n");
	if (!*backup)
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
			ft_free_all(&buffer, backup, NULL); // Quizas deberia recibir response y liberarlo. NO!
			return ;
		}
		buffer[chars_read] = '\0';
		*backup = ft_strjoin(*backup, buffer);
		if (ft_get_new_line_char_position(*backup) != 0)
			break ;
	}
	ft_free_all(&buffer, NULL, NULL);
}

char	*get_next_line(int fd)
{
	char static	*backup;
	char		*response;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	response = NULL;
	ft_read_file(fd, &backup);
	if (!backup)
		return (NULL);
	if (backup != NULL && *backup != '\0')
	{
		ft_reasign_backup(&backup, &response);
	}
	if (!response || *response == '\0')
	{
		ft_free_all(NULL, &backup, &response);
		return (NULL);
	}
	return (response);
}
