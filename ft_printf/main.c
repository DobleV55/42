#include "ft_printf.h"
#include "ft_printf.c"

int main()
{
	char	*s;

	s = "hola";
	ft_printf("pointer: %p\ncharacter: %c\ninteger: %i\nstring: %s\nunsigned int: %u\n", s, 'h', 23, "amado", 4294967295);
	//printf("\nunsigned int: %u\n", 4294967295);
	return (0);
}