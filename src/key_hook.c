/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:56:33 by proshchy          #+#    #+#             */
/*   Updated: 2018/03/05 13:56:35 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int 	key_hook(int key, t_mlx *d)
{
	if (key == ESC)
	{
		free(d);
		exit(0);
	}
	if (key == INCR)
		d->zoom *= 0.9;
	if (key == DECR)
		d->zoom *= 1.1;
	if (key == LEFT)
		d->move_x += 0.5;
	if (key == RIGHT)
		d->move_x -= 0.5;
	expose_hook(d);
	return (0);
}

int		ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}
