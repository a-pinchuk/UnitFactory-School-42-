/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcopy_fields.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:30:33 by rbozhko           #+#    #+#             */
/*   Updated: 2017/02/08 13:31:32 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_memcpy_flds(char **old_fld, char **new_fld, int t_num)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < t_num)
	{
		while (++j < t_num)
			(old_fld[i][j] == '#') ? new_fld[i][j] = old_fld[i][j] : 0;
		j = -1;
	}
	return (new_fld);
}
