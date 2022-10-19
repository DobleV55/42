#ifndef FT_PRINTF
#define FT_PRINTF
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
// printf
int ft_printf(const char *str, ...);
// printf %?
int	ft_putchar(char c);
int	ft_putstr(char *s, int order);
int	ft_putaddress(unsigned long num);
int	ft_putunbr(unsigned int num);
int	ft_puthexnbr_upper(unsigned int num);
int	ft_puthexnbr_lower(unsigned int num);
// libft extra
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
#endif
