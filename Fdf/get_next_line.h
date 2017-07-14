/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 16:05:23 by apinchuk          #+#    #+#             */
/*   Updated: 2017/07/06 14:02:31 by apinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NET_LINE_GET_NEXT_LINE_H
# define GET_NET_LINE_GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE 9999
# define GNL_ERROR_P_1 fd == -1 || (!line) || (read(fd, NULL, 0) == -1)
# define GNL_ERROR_P_2 !(ft_memset(buffer, 0, (BUFF_SIZE + 1)))
# define GNL_ERROR_CASES GNL_ERROR_P_1 || GNL_ERROR_P_2

typedef	struct		s_gnl
{
	int				fd;
	char			*str;
	char			*str_to_free;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(int fd, char **line);

#endif
