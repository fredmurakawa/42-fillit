/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtashako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:11:43 by jtashako          #+#    #+#             */
/*   Updated: 2018/05/08 15:20:04 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_s_point.h"

t_point		new_point(int x, int y)
{
	t_point new;

	new.row = x;
	new.col = y;
	return (new);
}
