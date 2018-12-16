/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:49:40 by jtashako          #+#    #+#             */
/*   Updated: 2018/05/08 15:23:14 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tet.h"
#include "solve.h"

t_point		place(t_point p, int board[g_board_size][g_board_size],
	t_tet tet, int c)
{
	int		i;
	int		j;
	int		flag;
	t_point	ret;

	ret.row = -1;
	ret.col = -1;
	flag = 0;
	i = p.row;
	while (i < g_board_size)
	{
		j = (!flag) ? p.col - 1 : -1;
		while (++j < g_board_size)
		{
			if (place_piece(new_point(i, j), board, tet, c))
			{
				ret.row = i;
				ret.col = j;
				return (ret);
			}
		}
		flag = 1;
		++i;
	}
	return (ret);
}

int			place_piece(t_point p, int board[g_board_size][g_board_size],
		t_tet tet, int c)
{
	int i;

	i = -1;
	while (++i < BLOCK_SIZE)
		if (!((tet.block[i].row + p.row) < g_board_size
			&& (tet.block[i].col + p.col) < g_board_size
			&& (board[p.row + tet.block[i].row]
				[p.col + tet.block[i].col]) == 46))
			return (0);
	i = -1;
	while (++i < BLOCK_SIZE)
		board[p.row + tet.block[i].row][p.col + tet.block[i].col] = c;
	return (1);
}

void		rm_piece(int board[g_board_size][g_board_size], int c)
{
	int		row;
	int		col;

	row = -1;
	while (++row < g_board_size)
	{
		col = -1;
		while (++col < g_board_size)
		{
			if (board[row][col] == c)
				board[row][col] = 46;
		}
	}
}

void		reduce_solve_rm_piece(int board[g_board_size][g_board_size], int i)
{
	rm_piece(board, 65 + i);
	g_tets[i].placed = 0;
}

void		print_board(int board[g_board_size][g_board_size], int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			ft_putchar(board[i][j]);
		}
		ft_putchar('\n');
	}
}
