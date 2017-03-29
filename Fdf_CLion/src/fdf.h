#ifndef FDF_H
#define FDF_H

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "minilibx/mlx.h"
#include "get_next_line.h"

# define PNT_DIST 20
# define WIDTH 1000
# define HEIGHT 1000
# define angle(speed) speed * 3.14 / 180

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
	int 			scale;
	char			*av;
	double			win_move_x;
	double			win_move_y;			
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*str;
	int 			sl;
	int				endian;
	int				bpp;
	t_pnt			***field_ptr;
}				t_env;

t_env		*fdf_create_structures_arr(char *av, t_env *e);
void		fdf_drawing_field(t_env *e);
void		fdf_no_map(void);
void		fdf_error(void);
int 		key_hook(int keycode, t_env *e);
void		fdf_img_to_centre(t_env *e);
void		fdf_create_new_img(t_env *e);
void		fdf_scale_incrs(t_env *e);
void		fdf_pos_zoom(t_env *e);
void		fdf_neg_zoom(t_env *e);
void        fdf_rotate_x_up(t_env *e);
void        fdf_rotate_x_down(t_env *e);
void        fdf_rotate_y_up(t_env *e);
void        fdf_rotate_y_down(t_env *e);
void        fdf_rotate_z_up(t_env *e);
void        fdf_rotate_z_down(t_env *e);
void        fdf_isometria(t_env *e);

#endif