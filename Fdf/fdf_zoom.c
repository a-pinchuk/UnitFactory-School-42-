#include "fdf.h"

void fdf_rotate_x_up(t_env *e)
{
	int x;
	int y;
    double tmpz;
    double tmpy;
    t_brezenheim b;

    y = -1;
    while (++y < e->ylen && (x = -1))
    {
        while (++x < e->xlen)
        {
            tmpz = e->field_ptr[y][x]->z;
            tmpy = e->field_ptr[y][x]->y;
			e->field_ptr[y][x]->y = tmpy * cos(ANGLE(e->scale)) + tmpz * sin(ANGLE(e->scale));
			e->field_ptr[y][x]->z = tmpy * (-sin(ANGLE(e->scale))) + tmpz * cos(ANGLE(e->scale));
		}
	}
    fdf_drawing_field(e, -1, -1, &b);
}

void fdf_rotate_x_down(t_env *e)
{
    int x;
    int y;
    double tmpy;
    double tmpz;
    t_brezenheim b;

	y = -1;
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			tmpz = e->field_ptr[y][x]->z;
			tmpy = e->field_ptr[y][x]->y;
			e->field_ptr[y][x]->y = tmpy * cos(ANGLE(e->scale)) + (-tmpz * sin(ANGLE(e->scale)));
			e->field_ptr[y][x]->z = (tmpy * (sin(ANGLE(e->scale)))) + tmpz * cos(ANGLE(e->scale));
		}
	}
    fdf_drawing_field(e, -1, -1, &b);
}

void fdf_rotate_y_up(t_env *e)
{
    int x;
    int y;
    double tmpz;
    double tmpx;
    t_brezenheim b;

    y = -1;
    while (++y < e->ylen && (x = -1))
    {
        while (++x < e->xlen)
        {
            tmpx = e->field_ptr[y][x]->x;
            tmpz = e->field_ptr[y][x]->z;
            e->field_ptr[y][x]->x = tmpx * (cos(ANGLE(e->scale))) + tmpz * (sin(ANGLE(e->scale)));
            e->field_ptr[y][x]->z = tmpx * (-sin(ANGLE(e->scale))) + tmpz * cos(ANGLE(e->scale));
        }
    }
    fdf_drawing_field(e, -1, -1, &b);
}

void fdf_rotate_y_down(t_env *e)
{
    int x;
    int y;
    double tmpz;
    double tmpx;
    t_brezenheim b;

    y = -1;
    while (++y < e->ylen && (x = -1))
    {
        while (++x < e->xlen)
        {
            tmpx = e->field_ptr[y][x]->x;
            tmpz = e->field_ptr[y][x]->z;
            e->field_ptr[y][x]->x = tmpx * (cos(ANGLE(e->scale))) + tmpz * (-sin(ANGLE(e->scale)));
            e->field_ptr[y][x]->z = tmpx * (sin(ANGLE(e->scale))) + tmpz * cos(ANGLE(e->scale));
        }
    }
    fdf_drawing_field(e, -1, -1, &b);
}

void fdf_rotate_z_up(t_env *e)
{
    int x;
    int y;
    double tmpx;
    double tmpy;
    t_brezenheim b;

    y = -1;
    while (++y < e->ylen && (x = -1))
    {
        printf("FIRST WHILE");
        while (++x < e->xlen)
        {
            printf("SECOND WHILE");
            tmpx = e->field_ptr[y][x]->x;
            tmpy = e->field_ptr[y][x]->y;
            e->field_ptr[y][x]->x = tmpx * (cos(ANGLE(e->scale))) + tmpy * (-sin(ANGLE(e->scale)));
            e->field_ptr[y][x]->y = tmpx * (sin(ANGLE(e->scale))) + tmpy * cos(ANGLE(e->scale));
        }
    }
    fdf_drawing_field(e, -1, -1, &b);
}

void fdf_rotate_z_down(t_env *e)
{
    int x;
    int y;
    double tmpx;
    double tmpy;
    t_brezenheim b;

    y = -1;
    while (++y < e->ylen && (x = -1))
    {
        while (++x < e->xlen)
        {
            tmpx = e->field_ptr[y][x]->x;
            tmpy = e->field_ptr[y][x]->y;
            e->field_ptr[y][x]->x = tmpx * (cos(ANGLE(e->scale))) + tmpy * (sin(ANGLE(e->scale)));
            e->field_ptr[y][x]->y = tmpx * (-sin(ANGLE(e->scale))) + tmpy * cos(ANGLE(e->scale));
        }
    }
    fdf_drawing_field(e, -1, -1, &b);
}

void			fdf_pos_zoom(t_env *e)
{
    int		x;
    int		y;
    t_brezenheim b;

	y = -1;
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			e->field_ptr[y][x]->x *= 1.1;
			e->field_ptr[y][x]->y *= 1.1;
		}
	}
    fdf_drawing_field(e, -1, -1, &b);
}

void			fdf_neg_zoom(t_env *e)
{
    int		x;
    int		y;
    t_brezenheim b;

	y = -1;
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			e->field_ptr[y][x]->x *= 0.9;
			e->field_ptr[y][x]->y *= 0.9;
		}
	}
    fdf_drawing_field(e, -1, -1, &b);
}
