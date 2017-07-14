/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 12:32:53 by apinchuk          #+#    #+#             */
/*   Updated: 2017/07/08 12:32:55 by apinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx_ptr, e->win_ptr);
		exit(0);
	}
	if (keycode == 69)
		fdf_pos_zoom(e);
	else if (keycode == 78)
		fdf_neg_zoom(e);
	else if (keycode == 87)
		e->scale = e->scale + 1;
	else if (keycode == 91)
		fdf_rotate_x_up(e);
	else if (keycode == 84)
		fdf_rotate_x_down(e);
	else if (keycode == 86)
		fdf_rotate_y_up(e);
	else if (keycode == 88)
		fdf_rotate_y_down(e);
	else if (keycode == 83)
		fdf_rotate_z_up(e);
	else if (keycode == 85)
		fdf_rotate_z_down(e);
	return (keycode);
}

void	display_menu(t_env *e)
{
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 20, 0x6EDBBA,
	"Control: ");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 34, 0x6EDBBA,
	"Press 4 or 6 to rotate along the y axis");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 48, 0x6EDBBA,
	"Press 2 or 8 to rotate along the x axis");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 62, 0x6EDBBA,
	"Press 1 or 3 to positive_zoom");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 76, 0x6EDBBA,
	"Press + or - to negative_zoom");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 90, 0x6EDBBA,
	"Press 5 to speed_up_the_project");
}

int		expose_hook(t_env *e)
{
	display_menu(e);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env			e;
	t_brezenheim	b;

	e.scale = 2;
	if (argc != 2)
	{
		printf("No map was passed ....\n");
		return (-1);
	}
	e.av = argv[0];
	e.mlx_ptr = mlx_init();
	e.win_ptr = mlx_new_window(e.mlx_ptr, HEIGHT, WIDTH, "FDF 42");
	e.img_ptr = NULL;
	b.error2 = 0;
	fdf_create_structures_arr(argv[1], &e);
	fdf_isometria(&e, &b);
	mlx_hook(e.win_ptr, 2, 0, key_hook, &e);
	mlx_expose_hook(e.win_ptr, expose_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
