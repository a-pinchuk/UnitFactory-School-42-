/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tetraminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:33:20 by rbozhko           #+#    #+#             */
/*   Updated: 2017/02/08 13:34:14 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_put_tetraminos(char **field, t_list *temp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (field[i])
	{
		while (field[i][j])
		{
			(field[i][j] == '?') ? field[i][j] = temp->tet_ind : 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (field);
}
