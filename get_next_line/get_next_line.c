#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //printf
#include <fcntl.h> //O_RDONLY

char	*get_next_line(int fd)
{
	static int		left;
	int				i;
	int				alread;
	char			actual_char;

	i = 0;
	alread = 0;
	char *s = (char *) malloc(BUFFER_SIZE + left);
	while (left)
	{
		read(fd, &actual_char, 1);
		s[i] = actual_char;
		i++;
		left--;
	}
	while (alread < BUFFER_SIZE)
	{
		read(fd, &actual_char, 1);
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