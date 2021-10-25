/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:49:21 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/01 15:13:01 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "fillit.h"

int			line_read(char tetri[5][5], char **line, int line_tetri,
		t_liste *liste)
{
	if (check_line(*line) == -1)
	{
		free_list(liste);
		write_error_message();
	}
	ft_strcpy(tetri[line_tetri], *line);
	if (line_tetri == 3)
	{
		tetri[4][0] = '\0';
		if (check_dot(tetri) != 12 || check_sharp(tetri) != 4)
		{
			free_list(liste);
			write_error_message();
		}
		list_add_last(liste, parse_tetri(tetri, liste));
	}
	line_tetri++;
	free(*line);
	return (line_tetri);
}

int			read_file(int fd, t_liste *liste)
{
	char		*line;
	char		tetri[5][5];
	int			line_tetri;

	line_tetri = 0;
	while (get_next_line(fd, &line))
	{
		if (line[0] != '\0')
		{
			line_tetri = line_read(tetri, &line, line_tetri, liste);
		}
		else
		{
			line_break(line_tetri, tetri, liste, &line);
			line_tetri = 0;
		}
	}
	if (line_tetri != 4 || check_dot(tetri) != 12 || check_sharp(tetri) != 4)
	{
		free_list(liste);
		write_error_message();
	}
	return (1);
}

int			open_file(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	return (fd);
}

int			main(int argc, char *argv[])
{
	int		fd;
	t_liste	*liste;

	if (argc != 2)
	{
		ft_putstr("usage : ./fillit [filename]\n");
		exit(EXIT_FAILURE);
	}
	fd = open_file(argv[1]);
	liste = list_init();
	read_file(fd, liste);
	solve_fillit(liste);
	return (0);
}
