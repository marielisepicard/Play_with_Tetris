/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:30:09 by mpicard           #+#    #+#             */
/*   Updated: 2018/12/21 16:14:37 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst1;
	char		*dst2;

	dst1 = (char *)dst;
	dst2 = (char *)src;
	i = 0;
	while (i < n)
	{
		dst1[i] = dst2[i];
		i++;
	}
	return (dst);
}
