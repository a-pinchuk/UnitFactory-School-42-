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

int		ft_end_of_field(t_list *figure, int i, int j, char **field)
{
	return ((field[figure->y[0] + i][figure->x[0] + j] != '\0' &&
		field[figure->y[1] + i][figure->x[1] + j] != '\0' &&
		field[figure->y[2] + i][figure->x[2] + j] != '\0' &&
		field[figure->y[3] + i][figure->x[3] + j] != '\0') ? 1 : 0);
}

int		ft_is_dot_and_app(t_list *figure, int i, int j, char **field)
{
	return ((field[figure->y[0] + i][figure->x[0] + j] == '.' &&
		field[figure->y[1] + i][figure->x[1] + j] == '.' &&
		field[figure->y[2] + i][figure->x[2] + j] == '.' &&
		field[figure->y[3] + i][figure->x[3] + j] == '.') ? 1 : 0);
}

int		ft_app_cube_size(char **field, t_list *head, int i)
{
	return ((field[i + ft_max_height(head->y)] &&
		((size_t)ft_max_width(head->x) + 1 <= ft_strlen(*field) &&
		ft_max_height(head->y) + 1 <= ft_rows_in_field(field))) ? 1 : 0);
}
