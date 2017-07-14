//
// Created by Andrey Pinchuk on 6/7/17.
//

#include "ft_printf.h"

void	ft_putstring(char const *s, short int flag)
{
    size_t		i;

    i = -1;
    if (s)
    {
        while (s[++i])
            ft_putchar_mod(s[i], flag);
    }
}

int		ft_putchar_mod(char c, short int flag)
{
    static int	counter = 0;
    int			temp;

    (!flag) ? write(1, &c, 1) : 0;
    counter++;
    if (flag)
    {
        temp = --counter;
        counter = 0;
        //printf("Number of characters: %d\n", temp);
        return (temp);
    }
    else
        return (0);
}