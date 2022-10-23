#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //printf
#include <fcntl.h> //O_RDONLY

// Hola buenos dias \n hola buenos dias

char	*get_next_line(int fd)
{
	int	i;

	i = 0;
	char *s = (char *) malloc(BUFFER_SIZE + 1);
	while (i < BUFFER_SIZE)
	{
		read(fd, s, 1);
		i++;
	}
	return (s);
}

int	main()
{
	int fd;
	fd = open("foo.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}