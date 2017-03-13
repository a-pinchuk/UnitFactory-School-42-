#include "fdf.h"


void	bresenheim_algorithm_floats(t_pnt *pnt1, t_pnt *pnt2, t_env *e)
{
	t_pnt		temp;
	double		t;
	double		k;

	temp = *pnt1;
	t = -(0.5);
	k = (pnt2->y - temp.y)/(pnt2->x - temp.x);
	//printf("X temp: %.1f\n", temp.x);
	printf("\n");
	printf("Y temp: %.1f\n", temp.y);
	//printf("X pnt2: %.1f\n", pnt2->x);
	printf("Y pnt2: %.1f\n", pnt2->y);
	//printf("\n");  
	while (temp.y != pnt2->y || temp.x != pnt2->x)
	{
		mlx_pixel_put(e->mlx_ptr, e->win_ptr, temp.x + 300, temp.y + 300, temp.color);
		t += k;
		if (t < 0)
			temp.x += 1;
		else if (t >= 0)
		{
			//temp.x += 1;
			temp.y += 1;
			t--;
		}
	}
	printf("After\n");
	printf("Y temp: %.1f\n", temp.y);
	//printf("X pnt2: %.1f\n", pnt2->x);
	printf("Y pnt2: %.1f\n", pnt2->y);
}

void	fdf_drawing_field(t_env *e)
{
	int		x;
	int		y;
	t_pnt	pnt;

	y = 0;
	x = 0;
	while (y < e->ylen)
	{
		printf("\nY:%i\n", y);
		while (x < e->xlen)
		{
			printf("X:%i", x);
			pnt = *(e->field_ptr[y][x]);
			(e->field_ptr[y][x + 1]) ? bresenheim_algorithm_floats(&pnt, e->field_ptr[y][x + 1], e) : 0;
			(e->field_ptr[y + 1][x]) ? bresenheim_algorithm_floats(&pnt, e->field_ptr[y + 1][x], e) : 0;
			x++;
		}
		y++;
		x = 0;
	}
}
