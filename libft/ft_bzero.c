#include <string.h>

void	*ft_bzero(void *s, size_t len)
{
	size_t	counter;
	char	*str;

	str = s;
	counter = 0;
	while (counter < len)
	{
		str[counter] = '\0';
		str++;
		counter++;
	}
	return (0);
}
