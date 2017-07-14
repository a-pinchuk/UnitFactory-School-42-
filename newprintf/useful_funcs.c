#include "ft_printf.h"

void	ft_putnstr(char *str, int end)
{
	int		i;

	i = 0;
	while (i < end)
		ft_putchar(str[i++]);
}
