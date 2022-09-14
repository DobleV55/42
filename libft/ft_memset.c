#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	char	replace_char;
	size_t	counter;

	str = (char *) b;
	replace_char = (char )c;
	counter = 0;
	while (counter < len)
	{
		*str = replace_char;
		str++;
		counter++;
	}
	return (0);
}
