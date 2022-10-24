#include "get_next_line.h"
#include "limits.h"
char	*get_next_line(int fd)
{
	static int		left;
	int				i;
	int				alread;
	char			actual_char;
	char			validate_file; //quizas sacar usar NULL instead;

	if (fd < 0 || read(fd, &validate_file, 0) == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	actual_char = 0;
	i = 0;
	alread = 0;
	char *s = (char *) malloc(BUFFER_SIZE + left);
	while (left)
	{
		if (read(fd, &actual_char, 1) == 0)
			return (0);
		s[i] = actual_char;
		i++;
		left--;
	}
	while (alread < BUFFER_SIZE)
	{
		if (read(fd, &actual_char, 1) == 0)
		{
			if (actual_char)
			{
				return (s);
			}
			else{
				free(s);
				return (NULL);
			}
		}
		s[i] = actual_char;
		i++;
		alread++;
		if (actual_char == '\n')
		{
			left = BUFFER_SIZE - i;
			return (s);
		}
	}
	return (s);
}
/*
int	main()
{
	char *s;
	int fd;
	fd = open("foo.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("0:%s", s);
	s = get_next_line(fd);
	printf("1:%s", s);
	s = get_next_line(fd);
	printf("2:%s", s);
	return (0);
}
*/