#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //printf
#include <fcntl.h> //O_RDONLY

// Hola buenos dias \n hola buenos dias

char	*get_next_line(int fd)
{
	static int		left;
	int				i;
	char			actual_char;

	i = 0;
	char *s = (char *) malloc(BUFFER_SIZE + left);
	while (left)
	{
		
	}
	while (i < BUFFER_SIZE)
	{
		read(fd, &actual_char, 1);
		s[i] = actual_char;
		i++;
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
	printf("%s", s);
	printf("termine00");
	s = get_next_line(fd);
	printf("%s", s);
	printf("termine01");
	s = get_next_line(fd);
	printf("%s", s);
	return (0);
}