/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:42:13 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/01 15:12:51 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		add_y(t_coord *coord_tab, int k, int j)
{
	int res;

	res = coord_tab[k].y - coord_tab[j].y;
	if (res < 0)
		res = -res;
	return (res);
}

int		add_x(t_coord *coord_tab, int k, int j)
{
	int res;

	res = coord_tab[k].x - coord_tab[j].x;
	if (res < 0)
		res = -res;
	return (res);
}

int		check_connection(t_coord *coord_tab)
{
	int tmp;

	tmp = 0;
	if (add_x(coord_tab, 0, 1) + (add_y(coord_tab, 0, 1)) == 1)
		tmp++;
	if (add_x(coord_tab, 0, 2) + (add_y(coord_tab, 0, 2)) == 1)
		tmp++;
	if (add_x(coord_tab, 0, 3) + (add_y(coord_tab, 0, 3)) == 1)
		tmp++;
	if (add_x(coord_tab, 1, 2) + (add_y(coord_tab, 1, 2)) == 1)
		tmp++;
	if (add_x(coord_tab, 1, 3) + (add_y(coord_tab, 1, 3)) == 1)
		tmp++;
	if (add_x(coord_tab, 2, 3) + (add_y(coord_tab, 2, 3)) == 1)
		tmp++;
	if (tmp >= 3)
		return (2);
	else
		return (0);
}

int		check_dot(char tab[5][5])
{
	int i;
	int j;
	int dot;

	i = 0;
	dot = 0;
	j = 0;
	while ((tab[i][0]) != '\0')
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '.')
				dot++;
			j++;
		}
		i++;
	}
	return (dot);
}

int		check_sharp(char tab[5][5])
{
	int i;
	int j;
	int sharp;

	i = 0;
	sharp = 0;
	while (*tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				sharp++;
			j++;
		}
		i++;
	}
	return (sharp);
}
