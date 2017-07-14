/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 12:49:57 by apinchuk          #+#    #+#             */
/*   Updated: 2017/06/29 15:59:04 by apinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl		*new_elem(int fd)
{
	t_gnl *temp;

	temp = (t_gnl*)malloc(sizeof(t_gnl));
	(fd >= 0) ? temp->fd = fd : 0;
	temp->str = ft_strnew(0);
	temp->next = NULL;
	return (temp);
}

t_gnl		*compare_fd(int fd, t_gnl *main_line)
{
	t_gnl	*i;

	i = main_line;
	while (i)
	{
		if (i->fd == fd)
			return (i);
		if (i->next == NULL)
			i->next = new_elem(fd);
		i = i->next;
	}
	return (i);
}

int			write_in_line(t_gnl *i, char **line, int flag)
{
	char *temp;

	if (flag == 1)
	{
		*line = ft_strsub(i->str, 0, (ft_strchr(i->str, 10) - i->str));
		temp = ft_strsub(i->str, (ft_strchr(i->str, 10) - i->str),
			ft_strlen(i->str));
		i->str = temp;
		return (1);
	}
	else
	{
		i->str[ft_strlen(i->str)] = '\n';
		i->str[ft_strlen(i->str) + 1] = '\0';
		return (0);
	}
}

int			get_next_line(const int fd, char **line)
{
	char				buffer[BUFF_SIZE + 1];
	static t_gnl		*main_line = NULL;
	ssize_t				symbols;
	t_gnl				*i;

	if (GNL_ERROR_CASES)
		return (-1);
	(main_line == NULL) ? main_line = new_elem(fd) : 0;
	i = compare_fd(fd, main_line);
	while ((symbols = read(fd, buffer, BUFF_SIZE)) >= 0)
	{
		(symbols < BUFF_SIZE) ? buffer[symbols] = '\0' : 0;
		(ft_strlen(buffer) > 0) ? i->str = ft_strjoin(i->str, buffer) : 0;
		i->str += (i->str[0] == '\n') ? 1 : 0;
		if (ft_strchr(i->str, 10))
			return (write_in_line(i, line, 1));
		if (i->str[ft_strlen(i->str) - 1] != '\n' && ft_strlen(buffer) == 0)
		{
			if (write_in_line(i, line, 0) == 0)
				continue ;
		}
		if (symbols == 0)
			return (0);
	}
	return (1);
}
