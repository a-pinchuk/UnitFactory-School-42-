#include "fdf.h"

static t_pnt		*fdf_create_point(double x, double y, double z)
{
	t_pnt	*point;

	point = (t_pnt*)malloc(sizeof(t_pnt));
	point->x = x * 20;
	point->y = y * 20;
	point->z = z;
	point->color = 0x00FE6B7A;//(int)point->z;
	return (point);
}

static void 	fdf_fullfil_field_s(t_env *e, char **temp, int y)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (temp[++i])
		e->field_ptr[y][++j] = fdf_create_point((double)i, (double)y, ((double)atoi(temp[i])));
	e->field_ptr[y][++j] = NULL;
}

static void 	fdf_fullfil_field_f(char *av, t_env *e)
{
	int		fd;
	int		y;
	int		i;
	char	*line;
	char	**temp;

	y = -1;
	if ((fd = open(av, O_RDONLY)) < 0)
		fdf_error();
	while (get_next_line(fd, &line) > 0)
	{		
		e->field_ptr[++y] = (t_pnt**)malloc(sizeof(t_pnt*) * e->xlen);
		temp = ft_strsplit(line, 32);
		fdf_fullfil_field_s(e, temp, y);
	}
	e->field_ptr[++y] = (t_pnt**)malloc(sizeof(t_pnt*) * e->xlen);
	close(fd);
}

void		fdf_create_structures_arr(char *av, t_env *e)
{
	int		fd;
	char	*line;
	char	**temp;
	int		i;

	i = 0;
	e->xlen = 0;
	e->ylen = 0;
	if ((fd = open(av, O_RDONLY)) < 0)
		fdf_error();
	while (get_next_line(fd, &line) > 0)
		e->ylen++;
	temp = ft_strsplit(line, ' ');
	while (temp[i++] != 0)
		e->xlen++;
	e->field_ptr = (t_pnt***)malloc(sizeof(t_pnt**) * e->ylen);
	close(fd);
	fdf_fullfil_field_f(av, e);
}