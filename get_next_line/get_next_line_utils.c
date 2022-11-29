#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_charjoin(char c, char const *s2)
{
	int		len_s2;
	char 	*s3;

	len_s2 = ft_strlen(s2);
	s3 = malloc(len_s2 + 1);
	if (!s3)
		return NULL;
	*s3 = c;
	s3++;
	while (*s2)
	{
		*s3 = *s2;
		s2++;
		s3++;
	}
	return s3-len_s2-1;
}

void	*ft_cpy_arr(char const *arr)
{
	int 	len_arr;
	char 	*str;

	if (!arr)
		return (NULL);
	len_arr = 0;
	while (arr[len_arr])
		len_arr++;
	if (len_arr == 0)
		return (NULL);
	str = (char *) malloc (len_arr + 1);
	if (!str)
		return (NULL);
	while (*arr)
	{
		*str = *arr;
		str++;
		arr++;
	}
	*str = '\0';
	return (str - len_arr);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if (!s1)
		return (ft_strdup(""));
	i = 0;
	while (s1[i])
		i++;
	s2 = ft_malloc_zero(i + 1, sizeof * s2);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

char	*ft_strjoin(char	*s1, char const	*s2)
{
	char	*s;
	int		len;
	int		i;

	len = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1 && s1[len])
		len++;
	i = 0;
	while (s2 && s2[i])
		i++;
	s = ft_malloc_zero(len + i + 1, sizeof * s);
	if (!s)
		return (NULL);
	len = -1;
	while (s1 && s1[++len])
		s[len] = s1[len];
	i = -1;
	while (s2 && s2[++i])
		s[len + i] = s2[i];
	return (s);
}
void	*ft_malloc_zero(size_t count, size_t size)
{
	void			*r;
	unsigned char	*p;
	size_t			total;

	total = count * size;
	r = malloc(total);
	if (!r)
		return (NULL);
	p = (unsigned char *)r;
	while (total != 0)
	{
		*p = '\0';
		p++;
		total--;
	}
	return (r);
}


int		contains_newline(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
int	ft_get_new_line_char_position(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char) '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strodup(const char *s, int offset, int end)
{
	int		size;
	int		i;
	char	*cp_str;

//	printf("------WELCOME TO STRODUP------\n");
//	printf("s: %s\n", s);
//	printf("s[0]: %c\n", s[0]);
//	printf("offset: %d\n", offset);
//	printf("end: %d\n", end);
	size = ft_strlen(s);
//	printf("size: %d\n", size);
	if (offset >= size || end < 0)
	{
//		printf("BAD INPUT!\n");
		return (NULL);
	}
	if (end > size)
	{
//		printf("BAD INPUT!\n");
		end = 0;
	}
//	printf("size - end: %d\n", (size - end));
	i = 0;
	if (end)
	{
		cp_str = (char *) malloc (end - offset + 1);
		if (!cp_str)
			return (NULL);
//		printf("malloc size END: %d\n", (end - offset));
//		printf("offset -> %d\n", offset);
//		printf("end -> %d\n", end);
		while (offset < end)
		{
//			printf("hi\n");
//			printf("copying s[%d] into cp_str[%d]: s[%d] -> %c\n", offset, i, offset, s[offset]);
			cp_str[i] = s[offset];
			offset++;
			i++;
		}
		cp_str[i] = '\0';
//		printf("cp_str: %s\n", cp_str);

	} else
	{
//		printf("morning\n");
		cp_str = (char *) malloc (size - offset + 1);
//		printf("malloc size OFFSET: %d\n", (size - offset + 1));
		if (!cp_str)
			return (NULL);
//		printf("offset -> %d\n", offset);
//		printf("end -> %d\n", end);
		while (offset < size)
		{
//			printf("hi\n");
//			printf("copying s[%d] into cp_str[%d]: s[%d] -> %c\n", offset, i, offset, s[offset]);
//			printf("i -> %d\n", i);
			cp_str[i] = s[offset];
			offset++;
			i++;
		}
//		printf("i -> %d\n", i);
		cp_str[i] = '\0';
//		printf("cp_str: %s\n", cp_str);
	}
//	printf("morning\n");
//	printf("strodup response: %s\n", cp_str);

//	printf("-----END OF STRODUP EXCELLENT-----\n");
	return (cp_str);
}

int	ft_strlcpy(char *restrict dst, const char *restrict src, int size)
{
	int	len_src;

	len_src = ft_strlen(src);
	while (size > 1 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	if (size > 0)
		*dst = '\0';
	return (len_src);
}
