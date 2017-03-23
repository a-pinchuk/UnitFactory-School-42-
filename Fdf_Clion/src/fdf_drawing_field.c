/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawing_field.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:28:00 by rbozhko           #+#    #+#             */
/*   Updated: 2017/03/22 14:34:46 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_drawing_pxl(t_env *e, int x, int y)
{
	if ((x < WIDTH && x >= 0) && (y < HEIGHT && y >= 0))
	{
		e->str[(4 * x + y * e->sl)] = 249;
		e->str[(4 * x + y * e->sl + 1)] = 188;
		e->str[(4 * x + y * e->sl + 2)] = 216;
	}
}

static void		fdf_bresenheim(t_pnt *pnt1, t_pnt *pnt2, t_env *e)
{
    int 	x1 = (int)pnt1->x;
    int 	x2 = (int)pnt2->x;
    int 	y1 = (int)pnt1->y;
    int 	y2 = (int)pnt2->y;
    const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    int error = deltaX - deltaY;
    fdf_drawing_pxl(e, x2, y2);
    while(x1 != x2 || y1 != y2)
    {
        fdf_drawing_pxl(e, x1, y1);
        const int error2 = error * 2;
        if(error2 > -deltaY)
        {
            error -= deltaY;
            x1 += signX;
        }
        if(error2 < deltaX)
        {
            error += deltaX;
            y1 += signY;
        }
    }
}


void			fdf_drawing_field(t_env *e)
{
	int		x;
	int		y;
	t_pnt	pnt;

	y = -1;
	if (e->img_ptr)
		mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	e->img_ptr = mlx_new_image(e->mlx_ptr, WIDTH, HEIGHT);
	e->str = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->sl, &e->endian);
	fdf_img_to_centre(e);
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			pnt = *(e->field_ptr[y][x]);
			if (e->field_ptr[y][x + 1])
				fdf_bresenheim(&pnt, e->field_ptr[y][x + 1], e);
			if (e->field_ptr[y + 1][x])
				fdf_bresenheim(&pnt, e->field_ptr[y + 1][x], e);
		}
	}
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
}
