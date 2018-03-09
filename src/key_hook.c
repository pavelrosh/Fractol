/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:56:33 by proshchy          #+#    #+#             */
/*   Updated: 2018/03/09 18:00:50 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	move_hook(int key, t_mlx *d)
{
	if (key == LEFT)
		d->move_x += 0.4 * d->zoom * 100;
	if (key == RIGHT)
		d->move_x -= 0.4 * d->zoom * 100;
	if (key == UP)
		d->move_y += 0.4 * d->zoom * 100;
	if (key == DOWN)
		d->move_y -= 0.4 * d->zoom * 100;
	if (key == SCHEME)
	{
		d->color_scheme++;
		if (d->color_scheme > 3)
			d->color_scheme = 1;
	}
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

int		fract_type_hook(int key, t_mlx *d)
{
	if (key == 18)
		d->fract_type = M;
	else if (key == 19)
		d->fract_type = J;
	else if (key == 20)
		d->fract_type = B;
	else if (key == 21)
		d->fract_type = N;
	else if (key == 23)
		d->fract_type = C;
	else
		return (0);
	mlx_data_init(d);
	expose_hook(d);
	return (0);
}

int		key_hook(int key, t_mlx *d)
{
	if (key == ESC)
	{
		free(d);
		exit(0);
	}
	move_hook(key, d);
	zoom_iter_hook(key, d);
	fract_type_hook(key, d);
	mlx_destroy_image(d->mlx, d->img);
	expose_hook(d);
	return (0);
}

int		ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}
