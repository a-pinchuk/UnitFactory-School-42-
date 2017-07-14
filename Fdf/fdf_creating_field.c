/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_creating_field.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 13:57:47 by apinchuk          #+#    #+#             */
/*   Updated: 2017/07/08 13:57:48 by apinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_pnt		*fdf_create_point(double x, double y, double z)
{
	t_pnt	*point;

	if (!(point = (t_pnt*)malloc(sizeof(t_pnt))))
		fdf_malloc_fail();
	point->x = x * PNT_DIST;
	point->y = y * PNT_DIST;
	point->z = z * PNT_DIST;
	point->color = 0x00FE6B7A;
	return (point);
}

static void			fdf_fullfil_field_s(t_env *e, char **temp, int y)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (temp[++i])
		e->field_ptr[y][++j] = fdf_create_point((double)i, (double)y,
			((double)atoi(temp[i])));
	e->field_ptr[y][++j] = NULL;
}

static void			fdf_fullfil_field_f(char *av, t_env *e, char **str, int i)
{
	int		fd;
	int		y;
	char	*line;
	char	**temp;
	int		counter;

	y = -1;
	if ((fd = open(av, O_RDONLY)) < 0)
		fdf_error(e);
	while (get_next_line(fd, &line) > 0)
	{
		counter = 0;
		i = 0;
		str = ft_strsplit(line, ' ');
		while (str[i++] != 0)
			counter++;
		(counter != e->xlen) ? fdf_wrong_size_error(1) : 0;
		if (!(e->field_ptr[++y] = (t_pnt**)malloc(sizeof(t_pnt*) * e->xlen)))
			fdf_malloc_fail();
		temp = ft_strsplit(line, 32);
		fdf_fullfil_field_s(e, temp, y);
	}
	e->field_ptr[++y] = (t_pnt**)malloc(sizeof(t_pnt*) * e->xlen);
	(y != e->ylen) ? fdf_wrong_size_error(1) : 0;
	close(fd);
}

t_env				*fdf_create_structures_arr(char *av, t_env *e)
{
	int		fd;
	char	*line;
	char	**temp;
	int		i;

	i = 0;
	e->xlen = 0;
	if ((fd = open(av, O_RDONLY)) < 0)
		fdf_error(e);
	(get_next_line(fd, &line) != 0) ? e->ylen = 1 : fdf_wrong_size_error(2);
	while (get_next_line(fd, &line) > 0)
		e->ylen++;
	temp = ft_strsplit(line, ' ');
	while (temp[i++] != 0)
		e->xlen++;
	if ((e->field_ptr = (t_pnt***)malloc(sizeof(t_pnt**) * e->ylen)) == NULL)
		fdf_malloc_fail();
	close(fd);
	fdf_fullfil_field_f(av, e, NULL, 0);
	return (e);
}
