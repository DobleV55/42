#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	*s;

	s = ft_itoa(n);
	if (s != NULL && fd != -1)
		write (fd, s, ft_strlen(s));
}
