#include <string.h>

char	*ft_itoa(int n)
{
	int		len_n;
	int		n_cpy;
	char	*res;

	n_cpy = n;
	len_n = 0;
	while (n > 0)
	{
		n = n / 10;
		len_n++;
	}
	res = (char *) malloc (len_n);
	len_n--;
	while (len_n >= 0)
	{
		res[len_n] = (n_cpy % 10) + '0';
		n_cpy = n_cpy / 10;
		len_n--;
	}
	return (res);
}
