/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:10:22 by proshchy          #+#    #+#             */
/*   Updated: 2018/03/05 14:10:33 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractal_calc(t_fract *fract, int iter)
{
	fract->n = 0;
	while (fract->n < iter && (fract->c_r * fract->c_r + fract->c_i * fract->c_i) < 4)
	{
		fract->c_rr = fract->c_r * fract->c_r - fract->c_i * fract->c_i;
		fract->c_ii = 2 * fract->c_r * fract->c_i;
		fract->c_r = fract->c_rr + fract->tmp_cr;
		fract->c_i = fract->c_ii + fract->tmp_ci;
		fract->n++;
	}
}

void	julia_f(t_mlx *d, t_fract *fract)
{
	fract->x = 0;
	fract->y = 0;
	fract->n = 0;

	while (fract->y < HEIGHT)
	{
		fract->c_r = (fract->x - WIDTH / 2.0) * (d->zoom) + d->move_x;
		fract->c_i = (fract->y - HEIGHT / 2.0) * (d->zoom) + d->move_y;
		fractal_calc(fract, d->iter);
		d->z = fract->c_r * fract->c_r + fract->c_i * fract->c_i;
		if (fract->n < d->iter)
			ft_draw(fract, d);
		if (fract->x < (WIDTH - 1))
			fract->x++;
		else
		{
			fract->x = 0;
			fract->y++;
		}
	}
}
