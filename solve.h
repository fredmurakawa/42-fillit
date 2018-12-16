/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:54:53 by jtashako          #+#    #+#             */
/*   Updated: 2018/05/08 14:56:12 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include "tet.h"
# include "ft_putchar.h"

int			solve(int board[g_board_size][g_board_size], t_tet tet,
	int n, int i);

#endif
