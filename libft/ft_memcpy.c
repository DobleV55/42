#include <string.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t		counter;
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	counter = 0;
	while (counter < n)
	{
		*dest = *source;
		dest++;
		source++;
		counter++;
	}
	*dest = '\0';
	return dst;
}
