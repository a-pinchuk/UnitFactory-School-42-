#ifndef FDF_H
#define FDF_H

#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_coor
{
	double	x;
	double 	y;
	double	z;
	int 	color;
}			t_coor;

typedef struct s_field
{
	t_coor 	**t_coors;
	int		len;
}			   t_field;

typedef struct 	s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*addr;
	int				endian;
	int				bpp;
	struct s_coor	***coors_arr;
}				t_env;

int				get_next_line(int fd, char **line);
char			**ft_strsplit(char const *s, char c);
#endif