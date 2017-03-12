#include "fdf.h"

void	fdf_drawing_field(t_env *e)
{
	int		x;
	int		y;
	t_pnt	pnt;

	y = 0;
	while ((y < e->ylen) && !(x = 0))
	{
		while (x < e->xlen) // calc the length of an array
		{
			pnt = *(e->field_ptr[y][x]);
			if (e->field_ptr[y][x + 1])
				bresenheim_algorithm_ints(e->field_ptr[y][x], e->field_ptr[y][x + 1], e);
			x++;
		}
		y++;
	}
}

// void	bresenheim_algorithm_floats(t_point *pnt1, t_point *pnt2, t_env *e)
// {
// 	t_point		temp
// 	double		t;
// 	double		k;

// 	temp = pnt1;
// 	t = -(0.5);
// 	k = (pnt2->y - temp.y)/(pnt2->x - temp.x); 
// 	while (temp.y != pnt2->y && temp.x != pnt2->x)
// 	{
// 		mlx_pixel_put(e->mlx_ptr, e->win_ptr, temp.x, temp.y, temp.color);
// 		t += k;
// 		if (t < 0)
// 			temp.x += 1;
// 		else if (t >= 0)
// 		{
// 			temp.x += 1;
// 			temp.y += 1;
// 			t--;
// 		}
// 	}
// }

void ft_draw(t_env *e, int a, int  b)
{
	int x;
	int y;

	y = 50;
	while(y < 500)
	{
		x = 50;
		while(x < 500)
		{
			mlx_pixel_put(e->mlx_ptr, e->win_ptr, x, y, 0x00FF00FF);
			while (x == 499 && y == 499)
				mlx_pixel_put(e->mlx_ptr, e->win_ptr, a + x, b + y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
}

void	bresenheim_algorithm_ints(t_pnt *pnt1, t_pnt *pnt2, t_env *e)
{
	t_pnt		temp;
	int 		dx;
	int 		dy;
	int 		k;
	int 	 	t;

	temp = *pnt1;
	dx = (pnt2->x - temp.x);
	dy = (pnt2->y - temp.y);
	t = (-(0.5) * (2*dx));
	k = (2*dy); 
	while (temp.y != pnt2->y && temp.x != pnt2->x)
	{
		//mlx_pixel_put(e->mlx_ptr, e->win_ptr, temp.x, temp.y, temp.color);
		ft_draw(e, temp.x, temp.y);
		t += k;
		if (t < 0)
			temp.x += 1;
		else if (t >= 0)
		{
			temp.x += 1;
			temp.y += 1;
			t -= (2*dx) ;
		}
	}
}