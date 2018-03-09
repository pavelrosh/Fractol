/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:11:09 by proshchy          #+#    #+#             */
/*   Updated: 2018/03/09 18:03:56 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		motion_hook(int x, int y, t_mlx *d)
{
	double new_cr;
	double new_ci;

	if (d->fract_type == J)
	{
		new_cr = (1 / (double)WIDTH * (double)x * 4) - 2;
		new_ci = (1 / (double)HEIGHT * (double)y * 4) - 2;
		d->tmp_cr = new_cr;
		d->tmp_ci = new_ci;
		mlx_destroy_image(d->mlx, d->img);
		expose_hook(d);
	}
	return (0);
}

int		mouse_hook(int key, int x, int y, t_mlx *d)
{
	int x_tmp;
	int y_tmp;

	x_tmp = x;
	y_tmp = y;
	if (key == MOUSE_UP)
	{
		d->zoom *= 0.9;
		mlx_destroy_image(d->mlx, d->img);
		expose_hook(d);
	}
	if (key == MOUSE_DOWN)
	{
		d->zoom *= 1.1;
		mlx_destroy_image(d->mlx, d->img);
		expose_hook(d);
	}
	return (0);
}
