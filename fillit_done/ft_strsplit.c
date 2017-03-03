/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:21:16 by opariy            #+#    #+#             */
/*   Updated: 2016/12/06 14:21:17 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	ft_assign(char **table, const char *str, char c, int words)
{
	int		i;
	char	*start;

	while (words--)
	{
		i = 0;
		while (*str == c && *str != '\0')
			str++;
		start = (char *)str;
		while (*str != c && *str != '\0')
			str++;
		*table = (char *)malloc(sizeof(char) * ((str - start) + 1));
		while (*start != c && *start != '\0')
		{
			(*table)[i] = *start;
			start++;
			i++;
		}
		(*table)[i] = '\0';
		table++;
	}
	(*table) = NULL;
}

char			**ft_strsplit(char const *s, char c, int words)
{
	char	**table;

	table = NULL;
	if (s != NULL)
	{
		if ((table = (char **)malloc(sizeof(char *) * (words + 1))))
			ft_assign(table, s, c, words);
	}
	return (table);
}
