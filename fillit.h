/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:52:17 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/01 15:06:04 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef	struct			s_tetris
{
	t_coord				*coord_tab;
	char				letter;
	struct s_tetris		*next;
}						t_tetris;

typedef	struct			s_liste
{
	t_tetris			*first;
	t_tetris			*last;
	int					size_liste;
}						t_liste;

char					**init_grid(int size);
char					**solve_fillit(t_liste *liste);
int						add_y(t_coord *coord_tab, int k, int j);
int						add_x(t_coord *coord_tab, int k, int j);
int						check_connection(t_coord *coord_tab);
int						check_dot(char tab[5][5]);
int						check_line(char *line);
int						check_sharp(char tab[5][5]);
int						find_size(int n);
int						get_next_line(const int fd, char **line);
int						main(int argc, char *argv[]);
int						open_file(char *filename);
int						put_tetri(char ***grid, t_tetris *tetri, int size,
		int i_grid);
int						read_file(int fd, t_liste *liste);
int						space_for_tetri(t_tetris *tetri, char ***grid,
		int i_grid, int j_grid);
t_coord					*parse_tetri(char tab[5][5], t_liste *liste);
t_liste					*list_init(void);
void					write_error_message(void);
void					line_break(int line_tetri, char tetri[5][5],
		t_liste *liste, char **line);
void					erase_tetri(t_tetris *tetri, char ***grid,
		int i_grid, int j_grid);
void					free_grid(char ***grid, int size);
void					free_list(t_liste *liste);
void					ft_putchar(char c);
void					list_add_last(t_liste *liste, t_coord *coord_tab);
void					list_print(t_liste *liste);
void					print_grid(char **grid, int size);
void					write_tetri(t_tetris *tetri, char ***grid,
		int i_grid, int j_grid);

#endif
