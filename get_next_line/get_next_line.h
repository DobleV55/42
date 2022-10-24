#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# define FD_SIZE 4096

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd);

#endif
