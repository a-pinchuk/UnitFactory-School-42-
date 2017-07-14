#ifndef FT_PRINTF
#define FT_PRINTF

# include "./libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>

#define sym_flags(c) ((c == '-' || c == '+' || c == '#' || c == '.' || c == ' ') ? (1) : (0))
#define cast_flags(c) ((c == 'h' || c == 'l' || c == 'j' || c == 'z') ? (1) : (0))
#define conversion_flags(x) ((x == '%' || x == 's' || x == 'S' || x == 'p' || x == 'd' || x == 'D'|| \
							x == 'i' || x == 'o' || x == 'O' || x == 'u' || x == 'U'|| \
							x == 'x' || x == 'X' || x == 'c' || x == 'C') ? 1 : 0)
#define typecast_flags_int(type) (((type == 'd') || (type == 'D') || (type == 'u') || (type == 'o') \
								|| (type == 'O') || (type == 'x') || (type == 'X')) ? 1 : 0);
#define typecast_flags_char(type) (((type == 'c') || (type == 's') || !(typecast_flags_int(type))) ? 1 : 0);

typedef struct 	s_instruction
{
    char 			type; //look above(flags array)
	int 			zero_padding: 2; // fullfil with 0's
	int 			width; //non-zero first digit, which specifies amount of spaces before output, but if '-' flag is presented amount of spaces after output
	int 			minus_flag; // - (minus flag), it overrrides zero_padding property, so no zero will be printed after output
	int 			precision; //. (dot flag), adds zeros at the beginning of the number, which gets printed, or if used with string specifies number of chars, which gets printed
	int 			alternative_form; //# (only applicable to o,O and x,X (without bonuses))
	int 			space; //spaces ' ' for sign -> only availiable for i, d, D. If argument < 0, minus sign overrides space for sign, otherwise it remains empty(' ').
	int 			plus; // overrides argument's '+' and space for sign(previous flag) if argument >= 0, otherwise minus gets printed and also overrides space for sign(previous flag).
	char 			*str;
	int 			chars;
    int				null_c;
	enum typecast {
		// http://www.cplusplus.com/reference/cstdio/printf/
		hh = 1, // if hhh -> h, as h(single) is greater(due to the memory usage than twice h -> hh), otherwise if hhhh -> hh, as it even, and both hh can be handled in this case in the second time.
		h = 2, // visit link above
		l = 3, // visit link above
		ll = 4, // visit link above
		j = 5, // visit link above
		z = 6// visit link above
	} types;
} t_instruction;

void	    ft_putnstr(char *str, int end);
int		    ft_printf_parse_plus(char *str, va_list ap, int chars, t_instruction *instruction);
char	    *ft_printf_omit_spaces(char *str);
void		zero_padding(t_instruction *instruction);
void		sign_flag(t_instruction *instruction);
char        *get_width_perfomer(t_instruction *instruction, int *i);
void		get_width_contoller(t_instruction *instruction);
int		ft_printf(const char *str, ...);
void        get_alterform_type(t_instruction *instruction);
void        get_spaces_instruction(t_instruction *instruction);
int         ft_char_numlen(char *str);
void        get_precision_sign(t_instruction *instruction);
void        ft_del_chars(t_instruction *instruction, char *ltrs_to_omit);
void		get_typecast_ltrs(t_instruction *instruction);
char *ft_itoa_base(long int n, int base, char specifier);
size_t	    arg_print(t_instruction *instruction, va_list ap);
t_instruction     *arg_print_int(t_instruction *instruction, va_list ap);
void        ft_main_function (t_instruction *instruction, va_list ap);
void	ft_putstring(char const *s, short int flag);
int		ft_putchar_mod(char c, short int flag);

#endif