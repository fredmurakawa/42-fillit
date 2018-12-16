/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbueno-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:17:22 by fbueno-m          #+#    #+#             */
/*   Updated: 2018/05/08 14:54:37 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTCHAR_H
# define FT_PUTCHAR_H

# include <unistd.h>
# include "tet.h"

void		ft_putchar(char c);
void		ft_putstr(char *s);
int			ft_strlen(char *s);
void		reset(void);
int			d2(void);

#endif
