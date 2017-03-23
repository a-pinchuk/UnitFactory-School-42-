#include "fdf.h"

void fdf_rotate_x_up(t_env *e)
{
	int x;
	int y;
	int tmpz;
	int tmpy;

    y = -1;
    while (++y < e->ylen && (x = -1))
    {
        while (++x < e->xlen)
        {
            tmpz = e->field_ptr[y][x]->z;
            tmpy = e->field_ptr[y][x]->y;
			e->field_ptr[y][x]->y = tmpy * cos(Q) + tmpz * sin(Q);
			e->field_ptr[y][x]->z = tmpy * (-sin(Q)) + tmpz * cos(Q);
		}
	}
    fdf_drawing_field(e);
}

void fdf_rotate_x_down(t_env *e)
{
	int x;
	int y;
	int tmpy;
    int tmpz;

	y = -1;
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			tmpz = e->field_ptr[y][x]->z;
			tmpy = e->field_ptr[y][x]->y;
			e->field_ptr[y][x]->y = tmpy * cos(Q) + (-tmpz * sin(Q));
			e->field_ptr[y][x]->z = (tmpy * (sin(Q))) + tmpz * cos(Q);
		}
	}
	fdf_drawing_field(e);
}

void fdf_rotate_y_left(t_env *e)
{
    int x;
    int y;
    int tmpy;
    int tmpz;
   // int tmpx;

    y = -1;
    while (++y < e->ylen && (x = -1))
    {
        while (++x < e->xlen)
        {
            //tmpx = e->field_ptr[y][x]->x;
            tmpy = e->field_ptr[y][x]->y;
            tmpz = e->field_ptr[y][x]->z;
            //e->field_ptr[y][x]->x = tmpx;
            e->field_ptr[y][x]->y = tmpy * (cos(Q)) - tmpz * (-sin(Q));
            e->field_ptr[y][x]->z = tmpy * (-sin(Q)) + tmpz * cos(Q);
        }
    }
    fdf_drawing_field(e);
}

void fdf_rotate_y_right(t_env *e)
{
    int x;
    int y;
    int tmpx;
    //int tmpy;
    int tmpz;

    y = -1;
    while (++y < e->ylen && (x = -1))
    {
        while (++x < e->xlen)
        {
            tmpx = e->field_ptr[y][x]->x;
            //tmpy = e->field_ptr[y][x]->y;
            tmpz = e->field_ptr[y][x]->z;
            e->field_ptr[y][x]->x = tmpx * cos(Q) + tmpz * (-sin(Q));
            //e->field_ptr[y][x]->y = tmpy;
            e->field_ptr[y][x]->z = tmpx * (-sin(Q)) + tmpz * cos(Q);
        }
    }
    fdf_drawing_field(e);
}

void			fdf_pos_zoom(t_env *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			e->field_ptr[y][x]->x *= 1.1;
			e->field_ptr[y][x]->y *= 1.1;
		}
	}
	fdf_drawing_field(e);
}

void			fdf_neg_zoom(t_env *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			e->field_ptr[y][x]->x *= 0.9;
			e->field_ptr[y][x]->y *= 0.9;
		}
	}
	fdf_drawing_field(e);
}
