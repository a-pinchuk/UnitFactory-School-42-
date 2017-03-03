/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_ltrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:23:17 by rbozhko           #+#    #+#             */
/*   Updated: 2017/02/08 13:24:04 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_remove_ltrs(t_list *figure, char **field)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (field[i] != NULL)
	{
		while (field[i][j] != '\0')
		{
			(field[i][j] == figure->tet_ind) ? field[i][j] = '.' : 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (field);
}
