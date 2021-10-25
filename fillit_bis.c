/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:43:45 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/01 15:13:12 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fillit.h"

int			check_line(char *line)
{
	int len;
	int i;

	len = ft_strlen(line);
	if (len != 4)
	{
		ft_putstr("error\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '#')
		{
			ft_putstr("error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}

void		write_error_message(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

void		end_pars(t_coord *coord_tab, t_liste *liste)
{
	int k;
	int mini;
	int minj;

	k = -1;
	mini = 6;
	minj = 6;
	while (k++ < 3)
	{
		if (coord_tab[k].x < mini)
			mini = coord_tab[k].x;
		if (coord_tab[k].y < minj)
			minj = coord_tab[k].y;
	}
	k = -1;
	while (k++ < 3)
	{
		coord_tab[k].x -= mini;
		coord_tab[k].y -= minj;
	}
	if (check_connection(coord_tab) == 0)
	{
		free_list(liste);
		write_error_message();
	}
}

t_coord		*parse_tetri(char tab[5][5], t_liste *liste)
{
	t_coord		*coord_tab;
	int			i;
	int			j;
	int			k;

	coord_tab = (t_coord*)malloc(sizeof(t_coord) * 4);
	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
			{
				coord_tab[k].x = i;
				coord_tab[k].y = j;
				k++;
			}
			j++;
		}
		i++;
	}
	end_pars(coord_tab, liste);
	return (coord_tab);
}

void		line_break(int line_tetri, char tetri[5][5],
		t_liste *liste, char **line)
{
	if (line_tetri != 4)
	{
		free_list(liste);
		write_error_message();
	}
	else
	{
		tetri[line_tetri][0] = '\0';
		tetri[line_tetri][1] = '\0';
		tetri[line_tetri][2] = '\0';
		tetri[line_tetri][3] = '\0';
		if (check_dot(tetri) != 12 || check_sharp(tetri) != 4)
		{
			ft_putstr("error\n");
			exit(EXIT_FAILURE);
		}
		line_tetri = 0;
	}
	free(*line);
}
