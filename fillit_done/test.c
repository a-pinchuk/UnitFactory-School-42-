/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:13:38 by rbozhko           #+#    #+#             */
/*   Updated: 2017/02/08 13:13:39 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_place(t_list *figure, char **field, int i, int j)
{
	t_list		*head;

	head = figure;
	if (!(head))
		return (12);
	else
	{
		while (ft_app_cube_size(field, head, i) && !(j = 0))
		{
			while (ft_end_of_field(figure, i, j, field))
			{
				if (ft_is_dot_and_app(figure, i, j, field))
				{
					field = ft_settle_figure(head, field, i, j);
					if ((ft_check_place(head->next, field, 0, 0)) == 12)
						return (12);
					else
						ft_remove_ltrs(head, field);
				}
				j++;
			}
			i++;
		}
	}
	return (0);
}

void	ft_putstr_cube(char **arr)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(arr[0]);
	i = 0;
	j = i;
	while (i < len)
	{
		while (j < len)
		{
			ft_putchar(arr[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

char	**ft_settle_figure(t_list *figure, char **field, int i, int j)
{
	field = ft_remove_ltrs(figure, field);
	field[figure->y[0] + i][figure->x[0] + j] = figure->tet_ind;
	field[figure->y[1] + i][figure->x[1] + j] = figure->tet_ind;
	field[figure->y[2] + i][figure->x[2] + j] = figure->tet_ind;
	field[figure->y[3] + i][figure->x[3] + j] = figure->tet_ind;
	return (field);
}

char	**building_cube(t_list *temp, char **field, int t_number)
{
	while ((ft_check_place(temp, field, 0, 0)) != 12)
		field = ft_generate_empty_field(++t_number, field);
	return (field);
}
