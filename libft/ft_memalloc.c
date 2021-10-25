/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:30:36 by mpicard           #+#    #+#             */
/*   Updated: 2018/12/21 16:05:04 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *i;

	if (!(i = (void *)malloc((sizeof(size_t) * size))))
		return (NULL);
	ft_bzero(i, size);
	return (i);
}
