#include "fdf.h"

void fdf_rotate_x_up(t_env *e)
{
	int x;
	int y;
    double tmpz;
    double tmpy;

    y = -1;
    while (++y < e->ylen && (x = -1))
    {
        while (++x < e->xlen)
        {
            tmpz = e->field_ptr[y][x]->z;
            tmpy = e->field_ptr[y][x]->y;
			e->field_ptr[y][x]->y = tmpy * cos(angle(e->scale)) + tmpz * sin(angle(e->scale));
			e->field_ptr[y][x]->z = tmpy * (-sin(angle(e->scale))) + tmpz * cos(angle(e->scale));
		}
	}
    fdf_drawing_field(e);
}

void fdf_rotate_x_down(t_env *e)
{
    int x;
    int y;
    double tmpy;
    double tmpz;

	y = -1;
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			tmpz = e->field_ptr[y][x]->z;
			tmpy = e->field_ptr[y][x]->y;
			e->field_ptr[y][x]->y = tmpy * cos(angle(e->scale)) + (-tmpz * sin(angle(e->scale)));
			e->field_ptr[y][x]->z = (tmpy * (sin(angle(e->scale)))) + tmpz * cos(angle(e->scale));
		}
	}
	fdf_drawing_field(e);
}

void fdf_rotate_y_up(t_env *e)
{
    int x;
    int y;
    double tmpz;
    double tmpx;

    y = -1;
    while (++y < e->ylen && (x = -1))
    {
        while (++x < e->xlen)
        {
            tmpx = e->field_ptr[y][x]->x;
            tmpz = e->field_ptr[y][x]->z;
            e->field_ptr[y][x]->x = tmpx * (cos(angle(e->scale))) + tmpz * (sin(angle(e->scale)));
            e->field_ptr[y][x]->z = tmpx * (-sin(angle(e->scale))) + tmpz * cos(angle(e->scale));
        }
    }
    fdf_drawing_field(e);
}

void fdf_rotate_y_down(t_env *e)
{
    int x;
    int y;
    double tmpz;
    double tmpx;

    y = -1;
    while (++y < e->ylen && (x = -1))
    {
        while (++x < e->xlen)
        {
            tmpx = e->field_ptr[y][x]->x;
            tmpz = e->field_ptr[y][x]->z;
            e->field_ptr[y][x]->x = tmpx * (cos(angle(e->scale))) + tmpz * (-sin(angle(e->scale)));
            e->field_ptr[y][x]->z = tmpx * (sin(angle(e->scale))) + tmpz * cos(angle(e->scale));
        }
    }
    fdf_drawing_field(e);
}

void fdf_rotate_z_up(t_env *e)
{
    int x;
    int y;
    double tmpx;
    double tmpy;

    y = -1;
    while (++y < e->ylen && (x = -1))
    {
        while (++x < e->xlen)
        {
            tmpx = e->field_ptr[y][x]->x;
            tmpy = e->field_ptr[y][x]->y;
            e->field_ptr[y][x]->x = tmpx * (cos(angle(e->scale))) + tmpy * (-sin(angle(e->scale)));
            e->field_ptr[y][x]->y = tmpx * (sin(angle(e->scale))) + tmpy * cos(angle(e->scale));
        }
    }
    fdf_drawing_field(e);
}

void fdf_rotate_z_down(t_env *e)
{
    int x;
    int y;
    double tmpx;
    double tmpy;

    y = -1;
    while (++y < e->ylen && (x = -1))
    {
        while (++x < e->xlen)
        {
            tmpx = e->field_ptr[y][x]->x;
            tmpy = e->field_ptr[y][x]->y;
            e->field_ptr[y][x]->x = tmpx * (cos(angle(e->scale))) + tmpy * (sin(angle(e->scale)));
            e->field_ptr[y][x]->y = tmpx * (-sin(angle(e->scale))) + tmpy * cos(angle(e->scale));
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
