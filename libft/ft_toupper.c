int	ft_toupper(int c)
{
	if (c >= 'a' && 'z' >= c) {
		return (c - 32);
	} else {
		return (c);
	}
}
