void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	count;

	count = 0;
	while (*s)
	{
		f (count, s);
		count++;
		s++;
	}
	return ;
}
