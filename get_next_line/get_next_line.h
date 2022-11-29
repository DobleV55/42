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
char	*ft_strchr(const char *s, int c);
char	*ft_charjoin(char c, char const *s2);
//
void	*ft_cpy_arr(char const *arr);
char	*search_new_line(const char *s);
int		ft_strlcpy(char *dst, const char *src, int size);
int		ft_get_new_line_char_position(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strodup(const char *s, int offset, int end);
void	ft_free_all(char **buffer, char **backup, char **response);
void	ft_strlocpy(char **dst, char **src, int offset);
void	ft_strlocpy(char **dst, char **src, int offset);
void	*ft_malloc_zero(size_t count, size_t size);
int		contains_newline(const char *s);

#endif
