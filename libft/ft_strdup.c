#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*str_cpy;
	int		len;

	len = 0;
	while (*s1)
	{
		s1++;
		len++;
	}
	str_cpy = (char *) malloc (len);
	s1 = s1 - len;
	while (*s1)
	{
		*str_cpy = *s1;
		str_cpy++;
		s1++;
	}
	return (str_cpy - len);
}
