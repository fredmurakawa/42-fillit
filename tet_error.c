/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:52:34 by jtashako          #+#    #+#             */
/*   Updated: 2018/05/08 14:52:38 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tet_error.h"
#include "tet_error2.h"

int			is_error(char **tet_file)
{
	if (tet_file == 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	if (!check_lines(tet_file))
	{
		ft_putstr("error\n");
		return (1);
	}
	if (!check_blocks(tet_file))
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

int			is_error2(int l)
{
	int i;

	if (l <= 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	i = -1;
	while (++i < l)
	{
		if (!check_tet(g_tets[i]))
		{
			ft_putstr("error\n");
			return (1);
		}
	}
	return (0);
}

static int	check_mid_line(int *k)
{
	if (*k != 4)
		return (0);
	else
		*k = 0;
	return (1);
}

int			check_blocks(char **tet_file)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	while (++i < g_lines)
	{
		if (i % 5 == 4)
			check_mid_line(&k);
		else
		{
			j = -1;
			while (++j < BLOCK_SIZE)
			{
				if (tet_file[i][j] != '#' && tet_file[i][j] != '.')
					return (0);
				if (tet_file[i][j] == '#')
					++k;
			}
		}
	}
	if (k != 4)
		return (0);
	return (1);
}

int			check_lines(char **tet_file)
{
	int i;

	i = -1;
	while (++i < g_lines)
	{
		if (i % 5 == 4)
		{
			if (ft_strlen(tet_file[i]) != 0)
				return (0);
		}
		else
		{
			if (ft_strlen(tet_file[i]) != BLOCK_SIZE)
				return (0);
		}
	}
	return (1);
}
