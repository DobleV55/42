#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL && fd != -1)
		write (fd, s, ft_strlen(s));
}
