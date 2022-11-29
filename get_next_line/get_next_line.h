#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //printf
#include <fcntl.h> //O_RDONLY
#include <limits.h> // ft_calloc
#include <string.h> // ft_strlen

char	*get_next_line(int df);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char	*s1, char const	*s2);
int		ft_get_new_line_char_position(const char *s);
char	*ft_strdup(const char *s1);
void	ft_free_all(char **buffer, char **backup, char **response);
void	*ft_calloc(size_t count, size_t size);
int		contains_newline(const char *s);

#endif
