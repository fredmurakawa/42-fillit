/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_read.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:55:41 by jtashako          #+#    #+#             */
/*   Updated: 2018/05/08 16:41:02 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TET_READ_H
# define TET_READ_H

# include "tet.h"
# include "ft_putchar.h"
# include <fcntl.h>
# include "grid.h"
# include "buf.h"

int			fill_board(int board[g_board_size][g_board_size]);
char		**read_file(char *file);
int			fill_tets(char **tet_file);

#endif
