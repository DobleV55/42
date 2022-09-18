#include "stdlib.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		count;
	char	*res;

	res = (char *) malloc (ft_strlen(s));
	count = 0;
	while (s[count])
	{
		res[count] = f(count, s[count]);
		count++;
	}
	return (res);
}
