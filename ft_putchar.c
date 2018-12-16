/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:26:08 by jtashako          #+#    #+#             */
/*   Updated: 2018/05/08 14:49:28 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putchar.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}

int		ft_strlen(char *s)
{
	int len;

	len = 0;
	while (*s)
	{
		++len;
		++s;
	}
	return (len);
}

int		d2(void)
{
	++g_pl;
	if (g_pl > SUB_SIZE)
		return (1);
	return (0);
}

void	reset(void)
{
	g_pl = 0;
}
