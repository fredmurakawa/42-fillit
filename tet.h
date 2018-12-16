/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:26:19 by jtashako          #+#    #+#             */
/*   Updated: 2018/05/08 16:24:29 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TET_H
# define FT_TET_H
# define TRUE 1
# define FALSE 0
# define BUFF_SIZE 32768
# define SUBSQUARE_SIZE 3
# define SUB_SIZE 10000
# define BLOCK_SIZE 4
# define BLOCK_N 26

# include <unistd.h>
# include "ft_s_point.h"

# ifndef FT_S_TETRIMINO_H
#  define FT_S_TETRIMINO_H

typedef	struct	s_tetrimino
{
	t_point		block[BLOCK_SIZE];
	int			placed;
}				t_tet;

int				g_board_size;
int				g_lines;
int				g_pl;
t_tet			g_tets[BLOCK_N];
int				g_k;
int				g_l;
int				g_min;
int				g_frow;
int				g_fcol;
int				g_valid;

# endif

void			ft_putchar(char c);
int				solve(int board[g_board_size][g_board_size],
										t_tet tet, int n, int i);
void			print_board(int board[g_board_size][g_board_size], int size);
t_point			place(t_point p, int board[g_board_size][g_board_size],
	t_tet tet, int c);
int				place_piece(t_point p,
		int board[g_board_size][g_board_size], t_tet tet, int c);
void			rm_piece(int board[g_board_size][g_board_size],
	int c);
void			reduce_solve_rm_piece(int board[g_board_size][g_board_size],
	int i);

#endif
