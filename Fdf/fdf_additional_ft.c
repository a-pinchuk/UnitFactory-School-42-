/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_additional_ft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 12:54:54 by apinchuk          #+#    #+#             */
/*   Updated: 2017/07/08 12:54:57 by apinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_img_to_centre(t_env *e)
{
	int		x;
	int		y;

	y = -1;
	e->win_move_x = (((e->field_ptr[e->ylen - 1]
	[e->xlen - 1]->x + e->field_ptr[0][0]->x) / 2));
	e->win_move_y = (((e->field_ptr[e->ylen - 1]
		[e->xlen - 1]->y + e->field_ptr[0][0]->y) / 2));
	while (++y < e->ylen && (x = -1))
	{
		while (++x < e->xlen)
		{
			e->field_ptr[y][x]->x += (HEIGHT / 2) - e->win_move_x;
			e->field_ptr[y][x]->y += (WIDTH / 2) - e->win_move_y;
		}
	}
}

void		fdf_isometria(t_env *e, t_brezenheim *b)
{
	int a;
	int i;

	a = 0;
	i = 0;
	while (a < e->ylen)
	{
		while (i < e->xlen)
		{
			e->field_ptr[a][i]->y = ((1 * e->field_ptr[a][i]->x) +
				(2 * e->field_ptr[a][i]->y) + (1 * e->field_ptr[a][i]->z))
			/ (sqrt(6));
			e->field_ptr[a][i]->x = ((sqrt(3) * e->field_ptr[a][i]->x) -
				(sqrt(3) * e->field_ptr[a][i]->z)) / (sqrt(6));
			i++;
		}
		i = 0;
		a++;
	}
	fdf_drawing_field(e, -1, -1, b);
}
