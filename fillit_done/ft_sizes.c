/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:19:15 by rbozhko           #+#    #+#             */
/*   Updated: 2017/02/08 13:21:18 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_max_width(int *arr)
{
	int		max_width;
	int		i;

	max_width = 0;
	i = -1;
	while (++i < 4)
		(arr[i] > max_width) ? max_width = arr[i] : 0;
	return (max_width);
}

int		ft_max_height(int *arr)
{
	int		max_height;
	int		i;

	max_height = 0;
	i = -1;
	while (++i < 4)
		(arr[i] > max_height) ? max_height = arr[i] : 0;
	return (max_height);
}

int		ft_rows_in_field(char **field)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	if (*field)
	{
		while (field[i++] != NULL)
			counter++;
	}
	return (counter);
}

void	return_error_message(void)
{
	write(1, "error\n", 6);
	exit(1);
}
