#ifndef FDF_H
#define FDF_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "minilibx/mlx.h"
#include "get_next_line.h"

typedef struct s_pnt
{
	double	x;
	double 	y;
	double	z;
	int 	color;
}			t_pnt;

typedef struct 	s_env
{
	int				xlen;
	int				ylen;			
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*addr;
	int				endian;
	int				bpp;
	t_pnt			***field_ptr;
}				t_env;

void		fdf_create_structures_arr(char *av, t_env *e);
void		fdf_drawing_field(t_env *e);
void		fdf_no_map(void);
void		fdf_error(void);
int 		key_hook(int keycode, t_env *e);
void	bresenheim_algorithm_ints(t_pnt *pnt1, t_pnt *pnt2, t_env *e);

#endif