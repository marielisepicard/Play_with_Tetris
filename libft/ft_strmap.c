/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:43:06 by mpicard           #+#    #+#             */
/*   Updated: 2018/12/12 11:29:40 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*s2;

	i = 0;
	if (!s)
		return (NULL);
	if (!(s2 = (char *)malloc((sizeof(char) * ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		s2[i] = (*f)(s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
