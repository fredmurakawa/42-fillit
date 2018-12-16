/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:50:48 by jtashako          #+#    #+#             */
/*   Updated: 2018/05/08 15:18:46 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

static int			reduce_solve(int board[g_board_size][g_board_size],
		int n, int i)
{
	int		x;
	int		y;
	t_point	res;

	x = -1;
	while (++x < g_board_size)
	{
		y = -1;
		while (++y < g_board_size)
		{
			res = place(new_point(x, y), board, g_tets[i], 65 + i);
			if (res.row != -1)
			{
				x = res.row;
				y = res.col;
				g_tets[i].placed = 1;
				if (solve(board, g_tets[i + 1], n, i + 1))
					return (1);
				else
					reduce_solve_rm_piece(board, i);
			}
		}
	}
	return (0);
}

static int			reduce_solve2(int board[g_board_size][g_board_size],
	int n, int i)
{
	if (g_tets[i].placed == 0)
		return (reduce_solve(board, n, i));
	else
		return (0);
}

static int			done(int n)
{
	int		k;
	int		ret;

	k = -1;
	ret = 1;
	while (++k < n)
		if (g_tets[k].placed == 0)
			ret = 0;
	return (ret);
}

static int			full_board(int board[g_board_size][g_board_size])
{
	int		i;
	int		j;

	i = -1;
	while (++i < g_board_size)
	{
		j = -1;
		while (++j < g_board_size)
			if (board[i][j] == '.')
				return (0);
	}
	return (1);
}

int					solve(int board[g_board_size][g_board_size], t_tet tet,
		int n, int i)
{
	if (done(n))
		return (1);
	else if (d2())
		return (0);
	else if (i >= n)
	{
		i = 0;
		tet = g_tets[i];
	}
	else if (full_board(board))
		return (0);
	if (reduce_solve2(board, n, i))
		return (1);
	return (0);
}
