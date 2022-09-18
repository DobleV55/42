int	ft_atoi(const char *str)
{
	int		sign;
	int		n;
	int		i;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] != '-' && str[i++] != '+')
		{
			if (*str == '-')
				sign = -1;
		}
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * sign);
}
