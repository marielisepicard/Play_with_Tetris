/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:46:58 by mpicard           #+#    #+#             */
/*   Updated: 2018/12/21 16:12:14 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *i;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = f(lst);
	i = new;
	while (lst->next != NULL)
	{
		new->next = f(lst->next);
		lst = lst->next;
		new = new->next;
	}
	new->next = NULL;
	return (i);
}
