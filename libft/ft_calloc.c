void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	r = malloc (count * size);
	if (r != 0)
	{
		return (r);
	}
	return (0);
}
