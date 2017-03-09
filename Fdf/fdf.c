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

// t_coor		*fdf_create_coor()
// {

// }

t_field		**fdf_create_structures_arr(char *av, int fd)
{
	char	*line;
	char	**temp;
	int 	counter;
	t_field	**field_arr;
	int		i;

	
	i = 0;
	counter = 0;
	if ((fd = open(av, O_RDONLY)) < 0)
	{
		printf("Error, openning failed ....\n");
		return (NULL);
	}
	while (get_next_line(fd, &line) > 0)
		counter++;
	temp = ft_strsplit(line, ' ');
	while (temp[i] != 0)
		i++;
	field_arr = (t_field**)malloc((sizeof(t_field*) * counter * i));
	printf("counter : %i\n", counter);
	printf("i : %i\n", i);
	close(fd);
	return (field_arr);
}

// int expose_hook(t_env *e)
// {
//  	ft_draw(e->mlx, e->win);
// 	return(0);
// }

int main(int argc, char **argv)
{
	t_env	*e;

	if (argc != 2)
	{
		printf("No map was passed ....\n");
		return (-1);
	}
	e = (t_env*)malloc(sizeof(t_env*));
	e->mlx_ptr = mlx_init();
	e->win_ptr = mlx_new_window(e->mlx_ptr, 1000, 1000, "FDF 42");
	fdf_create_structures_arr(argv[1], 0);
	mlx_key_hook(e->win_ptr, key_hook, e);
	//mlx_expose_hook(e.win_ptr, expose_hook, &e);
	mlx_loop(e->mlx_ptr);
	return (0);
}

// -lmlx -framework OpenGL -framework AppKit