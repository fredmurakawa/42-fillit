/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 20:41:43 by jtashako          #+#    #+#             */
/*   Updated: 2018/05/04 14:32:03 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"

char	*ft_getline(char *buf, int pos)
{
	int		start;
	int		i;
	char	*ret;

	start = pos;
	while (buf[pos] != '\n' && buf[pos] != '\0')
		++pos;
	ret = (char *)malloc(sizeof(char) * (pos - start) + 1);
	i = 0;
	while (i + start < pos)
	{
		ret[i] = buf[start + i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}

int		ft_endofline(char *buf, int pos)
{
	while (buf[pos] != '\n' && buf[pos] != '\0')
		++pos;
	return (pos);
}

int		ft_count_char(char *buf, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (buf[i])
	{
		if (buf[i] == c)
			++count;
		++i;
	}
	return (count);
}
