/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:34:52 by opariy            #+#    #+#             */
/*   Updated: 2016/12/23 14:34:54 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*realoc_n_copy(char *stdin, int len, int n)
{
	char *str;

	str = (char*)malloc((len) * sizeof(char));
	str = ft_strncpy(str, stdin, n);
	free(stdin);
	return (str);
}

char	*file_to_str(char *argv)
{
	char	*stdin;
	char	buf[1];
	int		i;
	int		len;
	int		fd;

	len = 10;
	stdin = (char *)malloc((len) * sizeof(char));
	i = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return_error_message();
	while (read(fd, buf, 1))
	{
		if (i == len - 1)
			stdin = realoc_n_copy(stdin, len *= 2, i);
		stdin[i++] = buf[0];
	}
	stdin[i] = '\0';
	if (ft_strlen(stdin) > 545)
		return_error_message();
	return (stdin);
}
