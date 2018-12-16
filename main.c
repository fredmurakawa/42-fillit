/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:26:13 by jtashako          #+#    #+#             */
/*   Updated: 2018/05/08 16:36:24 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tet.h"
#include "grid.h"
#include "buf.h"
#include "ft_putchar.h"
#include "tet_error.h"
#include "tet_read.h"
#include <fcntl.h>

int			try(int n, int size)
{
	int i;
	int board[g_board_size][g_board_size];

	g_board_size = size;
	fill_board(board);
	i = -1;
	while (++i < n)
	{
		if (solve(board, g_tets[i], n, i))
		{
			print_board(board, g_board_size);
			return (1);
		}
	}
	return (0);
}

int			main(int ac, char **av)
{
	char	**tet_file;
	int		l;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit [input_file]\n");
		return (0);
	}
	tet_file = read_file(av[1]);
	if (is_error(tet_file))
		return (0);
	l = fill_tets(tet_file);
	if (is_error2(l))
		return (0);
	while (l * 4 > g_board_size * g_board_size)
		++g_board_size;
	while (!try(l, g_board_size))
	{
		++g_board_size;
		reset();
	}
	return (0);
}
