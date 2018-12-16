/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:52:51 by jtashako          #+#    #+#             */
/*   Updated: 2018/05/08 16:38:21 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tet_read.h"

int					fill_board(int board[g_board_size][g_board_size])
{
	int i;
	int j;

	i = -1;
	while (++i < g_board_size)
	{
		j = -1;
		while (++j < g_board_size)
		{
			board[i][j] = 46;
		}
	}
	return (0);
}

char				**read_file(char *file)
{
	char	*buf;
	char	**tet_file;
	int		fd;
	char	ch;
	int		i;

	buf = (char *)malloc(sizeof(char) * BUFF_SIZE);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (read(fd, &ch, 1))
		buf[i++] = ch;
	tet_file = fill_grid(buf);
	return (tet_file);
}

static void			reduce_fill_tets2(char **tet_file, int row,
		int col, t_tet *new)
{
	while (++col < 4)
	{
		if (tet_file[row][col] == '#')
		{
			if (g_frow == -1 && g_fcol == -1)
			{
				g_frow = row;
				g_fcol = col;
			}
			new->block[g_k].row = row - g_frow;
			new->block[g_k].col = col - g_fcol;
			if (col - g_fcol < g_min)
				g_min = col - g_fcol;
			++g_k;
			if (g_k == 4)
			{
				if (g_min < 0)
					while (--g_k >= 0)
						new->block[g_k].col -= g_min;
				new->placed = 0;
				g_tets[g_l++] = *new;
				ft_adjust();
			}
		}
	}
}

static int			reduce_fill_tets(char **tet_file, int row,
		int col, t_tet new)
{
	while (tet_file[row] != 0)
	{
		g_min = 0;
		if (row % 5 == 4)
		{
			g_k = 0;
			g_frow = -1;
			g_fcol = -1;
		}
		col = -1;
		reduce_fill_tets2(tet_file, row, col, &new);
		++row;
	}
	return (g_l);
}

int					fill_tets(char **tet_file)
{
	int		row;
	int		col;
	t_tet	new;
	int		i;

	i = -1;
	while (++i < BLOCK_SIZE)
	{
		new.block[i].row = 0;
		new.block[i].col = 0;
	}
	g_l = 0;
	row = 0;
	g_frow = -1;
	g_fcol = -1;
	g_k = 0;
	col = -1;
	return (reduce_fill_tets(tet_file, row, col, new));
}
