//
// Created by Andrey Pinchuk on 4/28/17.
//

#include "ft_printf.h"




size_t			arg_print(t_instruction *instruction, va_list ap)
{
    char			c;
    long long int   nbr;

    c = instruction->type;
    nbr = (signed char)va_arg(ap, long long int);
    //printf("YA V ARG_PRINT\n");
    if (c == 'd' || c == 'i')
        return (arg_print_int(instruction, ap));
    if(c == 'x' || c == 'X')
        instruction->str = ft_itoa_base(nbr, 16, instruction->type);
    else if(c == 'u')
        instruction->str = ft_itoa_base(nbr, 10, instruction->type);
    else if(c == 'o')
        instruction->str = ft_itoa_base(nbr, 8, instruction->type);
   // printf("INSTRICTION STR: %s\n", instruction->str);
// else if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
//        return (arg_print_unsigned(instruction, c, ap));
    return (0);
}

t_instruction     *arg_print_int(t_instruction *instruction, va_list ap)
{
    long long int	nbr;


    if (instruction->types == 1)
        nbr = (signed char)va_arg(ap, long long int);
    else if (instruction->types == 2)
        nbr = (short int)va_arg(ap, long long int);
    else if (instruction->types == 3)
        nbr = (long int)va_arg(ap, long long int);
    else if (instruction->types == 4)
        nbr = (long long int)va_arg(ap, long long int);
    else if (instruction->types == 5)
        nbr = (intmax_t)va_arg(ap, long long int);
    else if (instruction->types == 6)
        nbr = (size_t)va_arg(ap, long long int);
    else
        nbr = (int)va_arg(ap, long long int);
    instruction->str = ft_itoa_base(nbr, 10, instruction->type);
    //printf("INSTRICTION STR: %s\n", instruction->str);
    return (instruction);
}

//t_instruction       *arg_print_unsigned(t_instruction *instruction, int modifier, va_list ap)
//{
//    unsigned long long int	nbr;
//
//    if (instruction->types == 1)
//        nbr = (unsigned char)va_arg(ap, long long int);
//    else if (instruction->types == 2)
//        nbr = (unsigned short int)va_arg(ap, long long int);
//    else if (instruction->types == 3)
//        nbr = (unsigned long int)va_arg(ap, long long int);
//    else if (instruction->types == 4)
//        nbr = (unsigned long long int)va_arg(ap, long long int);
//    else if (instruction->types == 5)
//        nbr = (uintmax_t)va_arg(ap, long long int);
//    else if (instruction->types == 6)
//        nbr = (size_t)va_arg(ap, long long int);
//    else
//        nbr = (unsigned int)va_arg(ap, long long int);
//    instruction->str
//    return (((void *)&nbr);
//}