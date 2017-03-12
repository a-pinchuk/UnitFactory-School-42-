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
	e.mlx_ptr = mlx_init();
	e.win_ptr = mlx_new_window(e.mlx_ptr, 1000, 1000, "FDF 42");
	fdf_create_structures_arr(argv[1], &e);
	mlx_key_hook(e.win_ptr, key_hook, &e);
	fdf_drawing_field(&e);
	//mlx_expose_hook(e.win_ptr, expose_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}

// -lmlx -framework OpenGL -framework AppKit