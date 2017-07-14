#include "ft_printf.h"

void    get_alterform_type(t_instruction *instruction)
{
    instruction->type = (char)instruction->str[ft_strlen(instruction->str) - 1];
    instruction->alternative_form = ((instruction->type == 'x' || instruction->type == 'X' ||
            instruction->type == 'o' || instruction->type == 'O') && ft_strchr(instruction->str, '#')) ? 1 : 0;
    ft_del_chars(instruction, "#");
    ft_del_chars(instruction, &instruction->str[ft_strlen(instruction->str) - 1]);
    //printf("instruction->type:  %c\n", instruction->type);
    //printf("instruction->alternative_form: %i\n", instruction->alternative_form);

}

void    get_spaces_instruction(t_instruction *instruction)
{
    char *tmp;
    int i;
    int j;

    i = 0;
    j = 0;
    tmp = (char *) malloc(ft_strlen(instruction->str) + 1);
    (ft_strchr(instruction->str, 32) ? tmp[j++] = ' ' : 0);
    while (instruction->str[++i])
        (instruction->str[i] != 32) ? tmp[j++] = instruction->str[i] : 0;
    tmp[j] = '\0';
    free(instruction->str);
    instruction->str = tmp;
    instruction->space = (ft_strchr(instruction->str, 32) ? 1 : 0);
    //printf("instruction->space:%d\n", instruction->space);
}

void    get_precision_sign(t_instruction *instruction)
{
    int     counter;

    counter = -1;
    instruction->precision = (ft_strchr(instruction->str, '.') ? 1 : 0);
    while (instruction->str[++counter] && instruction->precision)
    {
        if (instruction->str[counter] == '.')
        {
            if (instruction->str[counter + 1] >= 49 && instruction->str[counter + 1] <= 57) {
                counter += 1;
                instruction->precision = ft_atoi(get_width_perfomer(instruction, &(counter))) + 1;
            }
        }
    }
    instruction->precision -= 1;
    //printf("instruction->precision:%d\n", instruction->precision);
}

char        *ft_mutiply_str(char *str, unsigned int times)
{
    int     i;
    char    *tmp;

    i = -1;
    tmp = (char*)malloc(times + 1);
    while (++i < times)
        tmp[i] = str[0];
    tmp[i] = '\0';
    return (tmp);
}

int         ft_count_alpha(char *str, char c)
{
    int         i;
    int         counter;

    i = -1;
    counter = 0;
    while (str[++i])
        (str[i] == c) ? counter++ : 0;
    return (counter);
}

void        get_typecast_ltrs(t_instruction *instruction)
{
    instruction->types = 0;
    if (ft_strchr(instruction->str, 'h') || ft_strstr(instruction->str, "hh"))
    {
        instruction->types = ((ft_count_alpha(instruction->str, 'h') == 2) ? hh : h);
        ft_del_chars(instruction, ft_mutiply_str("h", (ft_count_alpha(instruction->str, 'h'))));
    }
    if (ft_strchr(instruction->str, 'l') || ft_strstr(instruction->str, "ll"))
    {
        instruction->types = ((ft_count_alpha(instruction->str, 'l') == 2) ? ll : l);
        ft_del_chars(instruction, ft_mutiply_str("l", (ft_count_alpha(instruction->str, 'l'))));
    }
    if (ft_strchr(instruction->str, 'j') || ft_strchr(instruction->str, 'z'))
    {
        if (ft_strchr(instruction->str, 'z'))
        {
            instruction->types = z; 
            ft_del_chars(instruction, "z");
        }
        else
        {
            instruction->types = j;
            ft_del_chars(instruction, "j");
        }
    }
}