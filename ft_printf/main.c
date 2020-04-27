#include "ft_printf.h"

int	main()
{
	int bite = ft_atoi("42");
	printf("%d\n", bite);
	ft_printf("%------*d\n", 4, 42);
	return (0);
}
