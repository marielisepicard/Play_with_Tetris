/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 11:48:35 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/01 15:11:22 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_grid(char ***grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free((*grid)[i]);
		i++;
	}
	free(*grid);
}

int		find_size(int n)
{
	int i;
	int j;

	i = n * 4;
	j = 0;
	while (j * j < i)
		j++;
	return (j);
}

void	erase_tetri(t_tetris *tetri, char ***grid, int i_grid, int j_grid)
{
	int k;
	int x;
	int y;

	k = 0;
	while (k < 4)
	{
		x = tetri->coord_tab[k].x + i_grid;
		y = tetri->coord_tab[k].y + j_grid;
		(*grid)[x][y] = '.';
		k++;
	}
}

void	write_tetri(t_tetris *tetri, char ***grid, int i_grid, int j_grid)
{
	int k;
	int x;
	int y;

	k = 0;
	while (k < 4)
	{
		x = tetri->coord_tab[k].x + i_grid;
		y = tetri->coord_tab[k].y + j_grid;
		(*grid)[x][y] = tetri->letter;
		k++;
	}
}

int		space_for_tetri(t_tetris *tetri, char ***grid,
		int i_grid, int j_grid)
{
	int k;
	int x;
	int y;
	int size;

	size = 0;
	while ((*grid)[size])
		size++;
	k = 0;
	while (k < 4)
	{
		x = tetri->coord_tab[k].x + i_grid;
		y = tetri->coord_tab[k].y + j_grid;
		if (x >= size || y >= size)
			return (0);
		else if ((*grid)[x][y] != '.')
			return (0);
		k++;
	}
	write_tetri(tetri, grid, i_grid, j_grid);
	return (1);
}
