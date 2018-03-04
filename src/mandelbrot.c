/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:55:41 by proshchy          #+#    #+#             */
/*   Updated: 2018/02/23 13:55:42 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	mandelbrot_calc(t_mlx *d, int iter)
{
	d->fract->n = -1;
	while (d->fract->n < iter && (d->fract->c_r * d->fract->c_r + d->fract->c_i * d->fract->c_i) < 4)
	{
		d->fract->c_rr = d->fract->c_r * d->fract->c_r - d->fract->c_i * d->fract->c_i;
		d->fract->c_ii = 2 * d->fract->c_r * d->fract->c_i;
		d->fract->c_r = d->fract->c_rr + d->fract->tmp_cr;
		d->fract->c_i = d->fract->c_ii + d->fract->tmp_ci;
		d->fract->n++;
	}
}

void	fractal_init(int iter, t_mlx *d)
{
	d->fract->x = 0;
	d->fract->y = 0;
	while (d->fract->y < HEIGHT)
	{
		d->fract->c_r = (d->fract->x - WIDTH / 2.0) * (d->zoom * ZOOM) + OFF_X;
		d->fract->c_i = (d->fract->y - HEIGHT / 2.0) * (d->zoom * ZOOM) + OFF_Y;
		d->fract->tmp_cr = 0.8;//d->fract->c_r;
		d->fract->tmp_ci = 0;//d->fract->c_i;
		mandelbrot_calc(d, iter);
		d->z = d->fract->c_r * d->fract->c_r + d->fract->c_i * d->fract->c_i;
		if (d->fract->n < iter)
			ft_draw(d->fract->x, d->fract->y, d->fract->n, d);
		if (d->fract->x < (WIDTH - 1))
			d->fract->x++;
		else
		{
			d->fract->x = 0;
			d->fract->y++;
		}
	}
}
