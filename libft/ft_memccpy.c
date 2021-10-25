/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:47:41 by mpicard           #+#    #+#             */
/*   Updated: 2018/12/21 16:15:35 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*src1;
	unsigned char	*dest2;
	size_t			i;

	src1 = (unsigned char *)src;
	dest2 = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dest2[i] = src1[i];
		if (src1[i] == (unsigned char)c)
			return ((void *)dst + i + 1);
		i++;
	}
	return (NULL);
}
