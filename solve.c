/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:51:58 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/01 15:11:13 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		put_tetri(char ***grid, t_tetris *tetri, int size, int i_grid)
{
	int j_grid;

	while (i_grid < size)
	{
		j_grid = 0;
		while (j_grid < size)
		{
			while (space_for_tetri(tetri, grid, i_grid, j_grid))
			{
				if (tetri->next != NULL)
				{
					if (put_tetri(grid, tetri->next, size, 0))
						return (1);
					else
						erase_tetri(tetri, grid, i_grid, j_grid);
					j_grid++;
				}
				else
					return (1);
			}
			j_grid++;
		}
		i_grid++;
	}
	return (0);
}

char	**init_grid(int size)
{
	char	**grid;
	int		i;
	int		j;

	if (!(grid = (char **)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(grid[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		j = 0;
		while (j < size)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\0';
		i++;
	}
	if (!(grid[i] = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	grid[i][0] = '\0';
	return (grid);
}

void	print_grid(char **grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
		i++;
	}
}

char	**solve_fillit(t_liste *liste)
{
	char		**grid;
	int			size;
	int			i_grid;
	t_tetris	*tetri;

	tetri = liste->first;
	i_grid = 0;
	size = find_size(liste->size_liste);
	grid = init_grid(size);
	while (put_tetri(&grid, tetri, size, i_grid) == 0)
	{
		free_grid(&grid, size);
		size++;
		grid = init_grid(size);
	}
	print_grid(grid, size);
	free_grid(&grid, size);
	free_list(liste);
	return (grid);
}
