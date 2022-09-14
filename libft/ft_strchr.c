char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while(*str)
	{
		if(*str == (char)c)
		{
			return (str);
		}
		str++;
	}
	return (0);
}
