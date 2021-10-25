/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:16:11 by mpicard           #+#    #+#             */
/*   Updated: 2018/12/21 15:59:24 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t ldst;
	size_t lsrc;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (ldst < size)
	{
		ft_strncat(dst, src, size - ldst - 1);
		return (lsrc + ldst);
	}
	else
		return (lsrc + size);
}
