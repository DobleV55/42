#include "ft_printf.h"
#include "ft_printf.c"

int main()
{
	char	*s;

	s = "hola";
	ft_printf("pointer: %s\ninteger: %i\nstring: %s\nchar: %c\nunsigned int: %u\nhexadecimal int (lower): %x\nhexadecimal int (upper): %X\nporcetage: %%\n", s, 123, s, 'c', 429496729, -1, -1);
	printf("\nnumber: %X\n", -1);
	return (0);
}