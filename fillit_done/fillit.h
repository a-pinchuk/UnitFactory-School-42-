/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:35:10 by opariy            #+#    #+#             */
/*   Updated: 2017/02/08 13:41:16 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_coordinates
{
	int				x;
	int				y;
}				t_coordinates;

typedef struct	s_tetriminos
{
	char			str[17];
	int				width;
	int				height;
	t_coordinates	coord[4];
}				t_tetriminos;

typedef struct	s_list
{
	char			tet_ind;
	int				x[4];
	int				y[4];
	struct s_list	*next;
}				t_list;

extern t_tetriminos	g_templates[19];

void			ft_putchar(char c);
int				ft_app_cube_size(char **field, t_list *head, int i);
int				ft_is_dot_and_app(t_list *figure, int i, int j, char **field);
int				ft_end_of_field(t_list *figure, int i, int j, char **field);
int				check_height(char *str, int words);
int				check_symbols(char *str);
void			ft_putstr(char *str);
char			**ft_strsplit(char const *s, char c, int words);
char			*file_to_str(char	*argv);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_count_words(char const *s, char c);
char			**ft_validate(char *str, int words);
char			*ft_strcat(char *s1, const char *s2);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
int				ft_compare_tetriminos(char **ttable, int tnumber);
int				ft_strcmp(const char *s1, const char *s2);
void			return_error_message(void);
size_t			ft_strlen(const char *s);
t_list			*str_to_list(char **str, int tnumber, int k, int m);
void			ft_move_up_left(char *str);
char			**ft_get_tetriminos(char **table, int words);
int				check_newline_quantity(char *str);
void			*ft_memcpy(void *destination, const void *source, size_t n);
char			ft_check_last_figure(char **field);
char			**ft_generate_empty_field(int t_number, char **field);
char			**ft_memcpy_flds(char **old_fld, char **new_fld, int t_num);
char			**ft_create_field(int square_side);
int				ft_rows_in_field(char **field);
int				ft_max_height(int *arr);
int				ft_max_width(int *arr);
char			**ft_remove_ltrs(t_list *figure, char **field);
char			**ft_settle_figure(t_list *figure, char **field, int i, int j);
char			**building_cube(t_list *temp, char **field, int t_number);
void			ft_putstr_cube(char **arr);
int				ft_rows_in_field(char **field);
#endif
