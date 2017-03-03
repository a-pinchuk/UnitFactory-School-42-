/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:41:09 by opariy            #+#    #+#             */
/*   Updated: 2017/02/08 13:24:59 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_words(char const *str, char c)
{
	int		counter;
	int		delimiter;

	counter = 0;
	delimiter = 1;
	while (*str)
	{
		if (delimiter == 1 && *str != c)
			delimiter = 0;
		if (delimiter == 0 && *str == c)
		{
			counter++;
			delimiter = 1;
		}
		str++;
	}
	return (counter);
}
