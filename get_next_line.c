/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 10:52:41 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/01 14:43:39 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int		nobackslashn(char const *stock, char **line, size_t len)
{
	if (len > 0)
	{
		*line = ft_strsub(stock, 0, len);
		ft_strclr((char *)stock);
		return (1);
	}
	*line = NULL;
	return (0);
}

int		ft_read(int fd, int ret, char buff[], char **stock)
{
	char	*tmp;
	char	c;

	c = '\n';
	while (ret > 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		tmp = *stock;
		*stock = ft_strjoin(tmp, buff);
		free(tmp);
		if (ft_strchr(buff, c) != NULL)
			break ;
	}
	return (0);
}

char	*ft_cut(char *stock, size_t len)
{
	size_t		i;
	char		*tmp;

	i = len;
	tmp = stock;
	while (stock[i] != '\0')
		i++;
	stock = ft_strsub(tmp, len, i);
	free(tmp);
	return (stock);
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*stock;
	char			c;
	int				ret;
	size_t			len;

	if (fd < 0 || line == NULL)
		return (-1);
	ret = 1;
	c = '\n';
	if (stock == NULL)
		if (!(stock = ft_strnew(1)))
			return (0);
	if (ft_read(fd, ret, buff, &stock) == -1)
		return (-1);
	len = 0;
	while (stock[len] != c && stock[len] != '\0')
		len++;
	if (ft_strchr(stock, c) == NULL)
		return (nobackslashn(stock, line, len));
	*line = ft_strsub(stock, 0, len);
	stock = ft_cut(stock, len + 1);
	if (*line != NULL || ret == BUFF_SIZE || ret < BUFF_SIZE)
		return (1);
	return (0);
}
