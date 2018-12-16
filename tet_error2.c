/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_error2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:52:43 by jtashako          #+#    #+#             */
/*   Updated: 2018/05/08 14:52:45 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tet_error2.h"

static void	reduce_check_tet(t_tet *tet, int i, int j, int *conn)
{
	int ret;

	ret = 0;
	if (i != j)
	{
		if (tet->block[i].row == tet->block[j].row &&
			(tet->block[i].col == tet->block[j].col - 1 ||
				tet->block[i].col == tet->block[j].col + 1))
		{
			g_valid = 1;
			++(*conn);
		}
		if (tet->block[i].col == tet->block[j].col &&
			(tet->block[i].row == tet->block[j].row - 1 ||
				tet->block[i].row == tet->block[j].row + 1))
		{
			g_valid = 1;
			++(*conn);
		}
	}
}

int			check_tet(t_tet tet)
{
	int i;
	int j;
	int conn;

	i = -1;
	conn = 0;
	while (++i < BLOCK_SIZE)
	{
		j = -1;
		g_valid = 0;
		while (++j < BLOCK_SIZE)
			reduce_check_tet(&tet, i, j, &conn);
		if (!g_valid)
			return (0);
	}
	if (conn != 6 && conn != 8)
		return (0);
	return (1);
}
