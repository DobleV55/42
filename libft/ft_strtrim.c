char	*ft_strtrim(char const *s1, char const *set)
{
	char	*left_index;
	char	*right_index;
	char	*r;
	int		len_r;

	left_index = (char *) s1;
	right_index = (char *) s1 + ft_strlen(s1) - 1;
	while (*left_index == *set)
		left_index++;
	while (*right_index == *set)
		right_index--;
	len_r = right_index - left_index + 1;
	r = (char *) malloc (right_index - left_index);
	while (left_index <= right_index)
	{
		*r = *left_index;
		left_index++;
		r++;
	}
	return (r - len_r);
}
