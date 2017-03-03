/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_empty_field.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:36:42 by opariy            #+#    #+#             */
/*   Updated: 2017/02/08 13:28:44 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_create_field(int square_side)
{
	char	**field;
	int		j;
	int		i;

	j = 0;
	field = (char **)malloc(sizeof(char *) * (square_side + 1));
	while (j < square_side)
	{
		i = 0;
		field[j] = (char *)malloc(sizeof(char) * (square_side + 1));
		while (i < square_side)
		{
			field[j][i] = '.';
			i++;
		}
		field[j][i] = '\0';
		j++;
	}
	field[j] = NULL;
	return (field);
}

char		**ft_generate_empty_field(int t_number, char **existing_field)
{
	int counter;
	int result;

	counter = 1;
	while (counter < t_number * 4 / counter + 1)
		counter++;
	result = counter;
	return (ft_memcpy_flds(existing_field, ft_create_field(counter), --result));
}
