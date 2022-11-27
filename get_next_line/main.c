#include "get_next_line.h"
#include <stdio.h> //printf
#include <fcntl.h> //O_RDONLY

int	main()
{
	int fd;
	fd = open("foo.txt", O_RDONLY);
	printf("returned: %s\n", get_next_line(fd));
	printf("returned: %s\n", get_next_line(fd));
	return (0);
}
