/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:45:07 by jtashako          #+#    #+#             */
/*   Updated: 2018/05/08 16:37:45 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

int		last_row(char **grid)
{
	int i;

	i = 1;
	while (grid[i])
		++i;
	return (i);
}

int		last_col(char **grid)
{
	int i;

	i = 0;
	while (grid[0][i])
		++i;
	return (i);
}

char	**fill_grid(char *buf)
{
	char	**grid;
	int		lines;
	int		i;
	int		last_pos;

	lines = ft_count_char(buf, '\n');
	g_lines = lines;
	grid = (char **)malloc(sizeof(char *) * (lines + 1));
	i = -1;
	last_pos = 0;
	while (++i < lines)
	{
		grid[i] = ft_getline(buf, last_pos);
		last_pos = ft_endofline(buf, last_pos) + 1;
	}
	grid[i] = 0;
	return (grid);
}

void	print_grid(char **grid)
{
	int i;

	i = -1;
	while (grid[++i] != 0)
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
	}
}

void	ft_adjust(void)
{
	if (g_tets[g_l - 1].block[0].row == 0
		&& g_tets[g_l - 1].block[0].col == 0 &&
		g_tets[g_l - 1].block[1].row == 1
		&& g_tets[g_l - 1].block[1].col == -1 &&
		g_tets[g_l - 1].block[2].row == 1
		&& g_tets[g_l - 1].block[2].col == 0 &&
		g_tets[g_l - 1].block[3].row == 2
		&& g_tets[g_l - 1].block[3].col == 0)
	{
		g_tets[g_l - 1].block[0].row = 0;
		g_tets[g_l - 1].block[0].col = 1;
		g_tets[g_l - 1].block[1].row = 1;
		g_tets[g_l - 1].block[1].col = 0;
		g_tets[g_l - 1].block[2].row = 1;
		g_tets[g_l - 1].block[2].col = 1;
		g_tets[g_l - 1].block[3].row = 2;
		g_tets[g_l - 1].block[3].col = 1;
	}
}
