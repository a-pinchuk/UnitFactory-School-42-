/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_last_figure.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:25:32 by rbozhko           #+#    #+#             */
/*   Updated: 2017/02/08 13:26:37 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_check_last_figure(char **field)
{
	char	ltr;
	int		i;
	int		j;

	ltr = 0;
	i = 0;
	j = 0;
	while (field[i])
	{
		while (field[i][j])
		{
			if ((field[i][j] >= 65 && field[i][j] <= 90) && ltr < field[i][j])
				ltr = field[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (ltr);
}
