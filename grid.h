/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:35:13 by jtashako          #+#    #+#             */
/*   Updated: 2018/05/08 16:34:14 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H

# include "buf.h"
# include "grid.h"
# include "ft_putchar.h"
# include "tet.h"

typedef struct	s_rowcol
{
	int ncol;
	int nrow;
}				t_rowcol;

int				last_row(char **grid);
int				last_col(char **grid);
char			**fill_grid(char *buf);
void			print_grid(char **grid);
void			ft_adjust(void);

#endif
