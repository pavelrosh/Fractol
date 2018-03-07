/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:29:10 by proshchy          #+#    #+#             */
/*   Updated: 2018/03/07 17:29:12 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fract_calc(t_fract *fract, int iter)
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

void	burning_ship_f(t_mlx *d, t_fract *fract)
{
	fract->x = 0;
	fract->y = 0;
	fract->n = 0;
	while (fract->y < HEIGHT)
	{
		fract->c_r = (fract->x - WIDTH / 2.0) * (d->zoom) + d->move_x;
		fract->c_i = (fract->y - HEIGHT / 2.0) * (d->zoom) + d->move_y;
		fract->tmp_cr = fract->c_r;
		fract->tmp_ci = fract->c_i;
		fract_calc(fract, d->iter);
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

