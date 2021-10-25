/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:51:20 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/01 15:12:22 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

t_liste			*list_init(void)
{
	t_liste		*liste;

	liste = malloc(sizeof(*liste));
	if (liste == NULL)
		exit(EXIT_FAILURE);
	liste->first = NULL;
	liste->last = NULL;
	liste->size_liste = 0;
	return (liste);
}

void			list_add_last(t_liste *liste, t_coord *coord_tab)
{
	t_tetris	*new;

	new = malloc(sizeof(*new));
	if (liste == NULL || new == NULL)
	{
		ft_putstr("error\n");
		exit(EXIT_FAILURE);
	}
	new->coord_tab = coord_tab;
	if (liste->first == NULL)
	{
		new->letter = 'A';
		new->next = NULL;
		liste->first = new;
		liste->last = new;
	}
	else
	{
		liste->last->next = new;
		new->letter = (liste->last->letter) + 1;
		new->next = NULL;
		liste->last = new;
	}
	liste->size_liste = (liste->size_liste) + 1;
}

void			free_list(t_liste *liste)
{
	t_tetris *actuel;
	t_tetris *tmp;

	actuel = liste->first;
	while (actuel != NULL)
	{
		free(actuel->coord_tab);
		tmp = actuel->next;
		free(actuel);
		actuel = tmp;
	}
	actuel = NULL;
	free(liste);
	liste = NULL;
}
