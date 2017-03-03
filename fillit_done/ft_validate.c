/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 20:11:24 by opariy            #+#    #+#             */
/*   Updated: 2016/12/23 20:11:26 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_get_tetriminos(char **table, int words)
{
	char	**table_tetriminos;
	int		j;
	int		str_counter;

	j = 0;
	str_counter = 0;
	table_tetriminos = (char **)malloc((sizeof(char *) * (words / 4)) + 1);
	while (str_counter < words / 4)
	{
		table_tetriminos[j] = ft_memalloc(17);
		j++;
		str_counter++;
	}
	str_counter = 0;
	j = 0;
	while (str_counter < words / 4)
	{
		ft_strcat(table_tetriminos[str_counter], table[j]);
		j++;
		if (j % 4 == 0)
			str_counter++;
	}
	return (table_tetriminos);
}

int		check_newline_quantity(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n'
			&& ((!(str[i + 2] == '#')) && (!(str[i + 2] == '.'))))
			return_error_message();
		i++;
	}
	return (1);
}

int		check_height(char *str, int words)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (words % 4 != 0)
		return_error_message();
	while (str[i] != '\0')
	{
		if ((i >= 20) && (i % (20 + j) == 0))
		{
			if (str[i] == '\n')
				j = j + 21;
			else
				return_error_message();
		}
		i++;
	}
	return (1);
}

int		check_symbols(char *str)
{
	int		i;
	int		last;
	int		counter;

	counter = 0;
	i = 0;
	last = ft_strlen(str);
	if ((str[last - 2] != '.') && (str[last - 2] != '#'))
		return_error_message();
	while (str[i] != '\0')
	{
		(str[i] == '#') ? counter++ : 0;
		if ((str[i] != '.') && (str[i] != '#') && (str[i] != '\n'))
			return_error_message();
		else
			i++;
	}
	return (counter > 0) ? 1 : 0;
}

char	**ft_validate(char *str, int words)
{
	char	**table;
	char	**table_tetriminos;

	if ((check_symbols(str) != 1) || (check_height(str, words) != 1) ||
		(check_newline_quantity(str) != 1))
		return (NULL);
	table = ft_strsplit(str, '\n', words);
	table_tetriminos = ft_get_tetriminos(table, words);
	if (ft_compare_tetriminos(table_tetriminos, words / 4) == 1)
		return (table_tetriminos);
	return (NULL);
}
