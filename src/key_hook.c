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

void	move_hook(int key, t_mlx *d)
{
	if (key == LEFT)
		d->move_x += 0.4;
	if (key == RIGHT)
		d->move_x -= 0.4;
	if (key == UP)
		d->move_y += 0.4;
	if (key == DOWN)
		d->move_y -= 0.4;
}

void	zoom_iter_hook(int key, t_mlx *d)
{
	if (key == INCR)
		d->zoom *= 0.9;
	if (key == DECR)
		d->zoom *= 1.1;
	if (key == INCR_I)
		d->iter += 5;
	if (key == DECR_I)
		d->iter -= 5; 
}

int 	key_hook(int key, t_mlx *d)
{
	if (key == ESC)
	{
		free(d);
		exit(0);
	}
	move_hook(key, d);
	zoom_iter_hook(key, d);
	if (key == SCHEME)
	{
		d->color_scheme++;
		if (d->color_scheme > 3)
			d->color_scheme = 1;
	}
	expose_hook(d);
	return (0);
}

int		ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}
