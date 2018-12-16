/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:11:53 by jtashako          #+#    #+#             */
/*   Updated: 2018/05/08 15:23:30 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_S_POINT_H
# define FT_S_POINT_H

typedef struct	s_point
{
	int			row;
	int			col;
}				t_point;

t_point			new_point(int x, int y);

#endif
