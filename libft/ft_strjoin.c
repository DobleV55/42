char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*s3;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = (char *) malloc (len_s1 + len_s2);
	while (*s1)
	{
		*s3 = *s1;
		s1++;
		s3++;
	}
	while (*s2)
	{
		*s3 = *s2;
		s2++;
		s3++;
	}
	return (s3 - (len_s1 + len_s2));
}
