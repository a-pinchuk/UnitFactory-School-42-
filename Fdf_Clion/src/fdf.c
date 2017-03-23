#include "fdf.h"

int 		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx_ptr, e->win_ptr);
		exit(0);
	}
	else
		printf("Keycode of the pressed button: %d\n", keycode);
	if (keycode == 69)
		fdf_pos_zoom(e);
	else if (keycode == 78)
		fdf_neg_zoom(e);
    else if (keycode == 91)
        fdf_rotate_x_up(e);
    else if (keycode == 84)
        fdf_rotate_x_down(e);
//    else if (keycode == 91)
//        fdf_rotate_up(e);
//    else if (keycode == 84)
//        fdf_rotate_down(e);
	return (keycode);
}


int main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
	{
		printf("No map was passed ....\n");
		return (-1);
	}
	e.av = argv[0];
	e.mlx_ptr = mlx_init();
	e.win_ptr = mlx_new_window(e.mlx_ptr, HEIGHT, WIDTH, "FDF 42");
	e.img_ptr = NULL;
	fdf_create_structures_arr(argv[1], &e);
    fdf_isometria(&e);
	fdf_drawing_field(&e);
	mlx_hook(e.win_ptr, 2, 0, key_hook, &e);
	//mlx_expose_hook(e.win_ptr, expose_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}