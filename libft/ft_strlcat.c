#include <string.h>

size_t	ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
		size_t		len_dst;

		len_dst = 0;
		while (*dst)
		{
			dst++;
			len_dst++;
		}
		while (len_dst < dstsize-1)
		{
			*dst = *src;
			dst++;
			src++;
			len_dst++;
		}
		*dst = '\0';
		return len_dst;
}