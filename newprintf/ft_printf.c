#include "ft_printf.h"

static int		ft_printf_allowed_compontents(char c)
{
	return ((sym_flags(c) || cast_flags(c) || ((c >= 48 && c <= 57) ? 1 : 0)) ? 1 : 0);
}

t_instruction 	*ft_printf_validing(const char *str, int chars, t_instruction *instruction)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[++i] && !(conversion_flags(str[i])) && (ft_printf_allowed_compontents(str[i])))
		;
	instruction->str = ((conversion_flags(str[i])) ? ft_strsub(str, 0, i + 1) : ft_strsub(str, 0, i + 1));
	instruction->chars += i;
	//printf("%s\n", instruction->str);
	return (instruction);
}


void ft_main_function (t_instruction *instruction, va_list ap)
{
    arg_print(instruction, ap);
}

t_instruction 	*ft_printf_parse_controller(va_list ap, t_instruction *instruction)
{
	//printf("1:%s\n", instruction->str);
	get_precision_sign(instruction);
	//printf("2:%s\n", instruction->str);
    get_width_contoller(instruction);
//printf("3:%s\n", instruction->str);
    zero_padding(instruction);
  //  printf("4:%s\n", instruction->str);
    sign_flag(instruction);
   // printf("5:%s\n", instruction->str);
	get_alterform_type(instruction);
	//printf("6:%s\n", instruction->str);
	get_typecast_ltrs(instruction);
	//printf("7:%s\n", instruction->str);
	get_spaces_instruction(instruction); //We delete % symbol here <-, so we need to remove it somewhere else
	//if we don't have spaces in the default instruction
    //After all stuff is done, and all other chars are deleted it is time to delete nums
   // printf("8:%s\n", instruction->str);
    ft_del_chars(instruction, "0123456789");
   // printf("9:%s\n", instruction->str);
    ft_del_chars(instruction, ".");
    //printf("9:%s\n", instruction->str);
    //And we can do something with that.
    // printf("instruction->type:%c\n", instruction->type); 
    // printf("instruction->zero_padding: %i\n", instruction->zero_padding);
    // printf("instruction->width: %i\n", instruction->width);
    // printf("instruction->minus_flag: %d\n", instruction->minus_flag);
    // printf("instruction->precision: %d\n", instruction->precision);
    // printf("instruction->alternative_form: %i\n", instruction->alternative_form);
    // printf("instruction->space: %d\n", instruction->space);
    // printf("instruction->plus_flag: %d\n", instruction->plus);
    // printf("instruction->types: %d\n", instruction->types);
    // printf("%s\n", instruction->str);

    ft_main_function(instruction, ap);
    ft_putstring(instruction->str, 0);
    (instruction->type == 'c' && instruction->null_c) ? ft_putchar_mod(0, 0) : 0;

	return (instruction);
}

int				ft_printf_processing(const char *str, va_list ap, int chars)
{
	char	*temp;
	t_instruction  instruction;

	temp = ft_strchr(str, '%');
	if (*str == '\0' || str == NULL)
		return (-1);
	else if (temp == NULL)
	{
		ft_putstring(str, 0);
	}
	else if (temp > str)
	{
		ft_putnstr((char*)str, (temp - str));
		return (ft_printf_processing(temp, ap, chars + (temp - str)));
	}
	else
	{
		if ((ft_printf_parse_controller(ap, ft_printf_validing(str, chars, &instruction))) == NULL)
			return (-1);
		/*else
			ft_printf_processing( with some valid parameters for next iteration with instruction, like str, chars and ap )*/
	}
	return (chars);
}

int			ft_printf(const char *str, ...)
{
	va_list ap;

	va_start(ap, str);
	ft_printf_processing(str, ap, 0);
	va_end(ap);
    return (ft_putchar_mod(0, 1));
}
