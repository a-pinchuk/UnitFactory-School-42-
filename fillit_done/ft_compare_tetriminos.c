/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_tetriminos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 14:00:25 by opariy            #+#    #+#             */
/*   Updated: 2016/12/26 14:00:28 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	move_up(char *str)
{
	int	i;

	i = -1;
	while (++i < 12)
		str[i] = str[i + 4];
	str[12] = '.';
	str[13] = '.';
	str[14] = '.';
	str[15] = '.';
	str[16] = '\0';
}

void	move_left(char *str)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		str[i] = str[i + 1];
		if (((i + 1) % 4 == 0))
			str[i] = '.';
	}
	str[16] = '\0';
}

void	ft_move_up_left(char *str)
{
	while ((str[0] == '.') && (str[1] == '.') && (str[2] == '.')
		&& (str[3] == '.'))
		move_up(str);
	while ((str[0] == '.') && (str[4] == '.') && (str[8] == '.')
		&& (str[12] == '.'))
		move_left(str);
}

int		ft_compare_tetriminos(char **ttable, int tnumber)
{
	int		i;
	int		result;
	int		j;

	result = 0;
	i = 0;
	while (i < tnumber)
		ft_move_up_left(ttable[i++]);
	i = -1;
	while (++i < 19)
	{
		j = 0;
		while (j < tnumber)
			((ft_strcmp(g_templates[i].str, ttable[j++])) == 0) ? result++ : 0;
	}
	return (result == tnumber) ? 1 : 0;
}
