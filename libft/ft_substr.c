#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*r;
	int		r_size;

	i = 0;
	while (s[i] != start && i < len && s[i])
		i++;
	r = malloc (len - i);
	r_size = len - i;
	while (i < len)
	{
		*r = s[i];
		i++;
		r++;
	}
	return (r - r_size);
}
