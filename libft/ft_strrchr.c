char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		str++;
	}
	str--;
	while (*str)
	{
		if (*str == (char) c)
		{
			return (str);
		}
		str--;
	}
	return (0);
}
