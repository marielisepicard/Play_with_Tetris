/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:43:51 by mpicard           #+#    #+#             */
/*   Updated: 2018/12/12 13:20:58 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	size_t	len;
	char	*s2;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[len] != '\0')
		len++;
	if (len == (unsigned)i)
		return (ft_strnew(0));
	while (s[len] == '\0' || s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	len = len + 1;
	s2 = ft_strsub(s, i, len - i);
	return (s2);
}
