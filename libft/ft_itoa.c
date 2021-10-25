/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:41:53 by mpicard           #+#    #+#             */
/*   Updated: 2018/12/21 16:08:35 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill(int n, int count, char *str)
{
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		count = count - 1;
		str[count] = '0' + (n % 10);
		n = n / 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		count;

	count = (n <= 0);
	i = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (i != 0)
	{
		i /= 10;
		count++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	str[count] = 0;
	ft_fill(n, count, str);
	return (str);
}
