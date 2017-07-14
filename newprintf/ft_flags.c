#include "ft_printf.h"

int         ft_strlen_mod(char *str, char *ltrs_to_omit)
{
    int         counter;
    int         i;

    i = -1;
    counter = 0;
    while (str[++i])
        (!(ft_strchr(ltrs_to_omit, str[i])) ? counter++ : 0);
    return (counter);
}

void        ft_del_chars(t_instruction *instruction, char *ltrs_to_omit)
{
    char    *tmp;
    int     i;
    int     j;

    tmp = (char*)malloc(ft_strlen_mod(instruction->str, ltrs_to_omit) + 1);
    i = -1;
    j = -1;
    while (instruction->str[++i])
    {
        (!(ft_strchr(ltrs_to_omit, instruction->str[i])) ? tmp[++j] = instruction->str[i] : 0);
    }
    free(instruction->str);
    tmp[++j] = '\0';
    instruction->str = tmp;
}

void		zero_padding(t_instruction *instruction)
{
    int 	i;

    i = -1;
    while(instruction->str[++i])
    {
        if ((instruction->str[i] == '0') && !(ft_isdigit(instruction->str[i - 1]))
            && (instruction->str[i - 1] != '.'))
        {
            instruction->zero_padding = 1;
            break ;
        }
        else
            instruction->zero_padding = 0;
    }
    //printf("instruction->zero_padding: %i\n", instruction->zero_padding);
}

void		sign_flag(t_instruction *instruction)
{
    if (ft_strchr(instruction->str, '-') != NULL)
    {
        ft_del_chars(instruction, "-");
        instruction->minus_flag = 1;
    }
    else
        instruction->minus_flag = 0;
    if (ft_strchr(instruction->str, '+') != NULL)
    {
        ft_del_chars(instruction, "+");
        instruction->plus = 1;
    }
    else
        instruction->plus = 0;
    //printf("instruction->minus_flag: %d\n", instruction->minus_flag);
    //printf("instruction->plus_flag: %d\n", instruction->plus);
}

int      ft_char_numlen(char *str)
{
    int counter;
    int i;

    i = -1;
    counter = 0;
    while (ft_isdigit(str[++i]))
        counter++;
    return (counter);
}

char     *get_width_perfomer(t_instruction *instruction, int *i)
{
    int k;
    char *num;

    k = 0;
    num = (char*)malloc(ft_char_numlen(instruction->str) + 1);
    while (ft_isdigit(instruction->str[(*i)]))
        num[k++] = instruction->str[(*i)++];
    num[k] = '\0';
    return (num);
}

void		get_width_contoller(t_instruction *instruction)
{
    int 		i;

    i = -1;
    instruction->width = 0;
    while (instruction->str[++i])
    {
        if (instruction->str[i] >= 49 && instruction->str[i] <= 57)
            instruction->width = ft_atoi(get_width_perfomer(instruction, &i));
    }
    //printf("WIDTH: %i\n", instruction->width);
}
