/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:56:50 by jtashako          #+#    #+#             */
/*   Updated: 2018/05/08 14:57:39 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TET_ERROR_H
# define TET_ERROR_H

# include "tet.h"
# include "ft_putchar.h"

int			is_error(char **tet_file);
int			is_error2(int l);
int			check_blocks(char **tet_file);
int			check_lines(char **tet_file);

#endif
