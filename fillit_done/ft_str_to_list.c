/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 10:11:49 by rbozhko           #+#    #+#             */
/*   Updated: 2017/02/08 13:40:28 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_create_elem(char tet_ind, int x[4], int y[4])
{
	t_list *head;

	head = (t_list *)malloc(sizeof(t_list));
	if (head)
	{
		head->next = NULL;
		ft_memcpy(head->x, x, 16);
		ft_memcpy(head->y, y, 16);
		head->tet_ind = tet_ind;
		return (head);
	}
	return (NULL);
}

t_list	*ft_list_push_back(t_list *begin_list, char tet_ind, int x[4], int y[4])
{
	t_list		*current;

	current = begin_list;
	if (!begin_list)
	{
		begin_list = ft_create_elem(tet_ind, x, y);
	}
	else
	{
		while (current->next)
			current = current->next;
		current->next = ft_create_elem(tet_ind, x, y);
	}
	return (begin_list);
}

t_list	*str_to_list(char **str, int tnumber, int k, int m)
{
	int			x[4];
	int			y[4];
	t_list		*begin_list;
	int			counter;

	begin_list = NULL;
	while (tnumber-- && !(counter = 0))
	{
		while (str[m][++k] != '\0')
		{
			if (str[m][k] == '#')
			{
				x[counter] = k % 4;
				y[counter++] = ((k / 4) >= 0) ? k / 4 : 0;
				if (counter == 4)
				{
					begin_list = ft_list_push_back(begin_list, m + 65, x, y);
					counter = 0;
				}
			}
		}
		k = -1;
		m++;
	}
	return (begin_list);
}
