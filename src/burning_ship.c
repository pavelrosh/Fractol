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

void	calc_ship(t_fract *fract, int iter)
{
	fract->n = 0;
	while (fract->n < iter && (fract->c_r * fract->c_r + fract->c_i * fract->c_i) < 4)
	{
		fract->c_rr = fract->c_r * fract->c_r;
		fract->c_ii = fract->c_i * fract->c_i;
		fract->c_i = fabs(fract->c_r * fract->c_i) * 2 + fract->tmp_ci;
		fract->c_r = fract->c_rr - fract->c_ii + fract->tmp_cr;
		fract->n++;
	}
}

void	*burning_ship_f(void *args)
{
	t_fract *fract = (t_fract *)args;
	fract->x = 0;
	fract->n = 0;
	while (fract->y_start < fract->y_end)
	{
		fract->c_r = (fract->x - WIDTH / 2.0) * fract->zoom + fract->move_x;
		fract->c_i = (fract->y_start - HEIGHT / 2.0) * fract->zoom + fract->move_y;
		fract->tmp_cr = fract->c_r;
		fract->tmp_ci = fract->c_i;
		calc_ship(fract, fract->iter);
		fract->z = fract->c_r * fract->c_r + fract->c_i * fract->c_i;
		if (fract->n < fract->iter)
			ft_draw(fract, fract->d);
		if (fract->x < (WIDTH - 1))
			fract->x++;
		else
		{
			fract->x = 0;
			fract->y_start++;
		}
	}
	pthread_exit(0);
}

void	p_tread_init_b(t_mlx *d)
{
	pthread_t	thread[16];
	t_fract		fract[16];
	int 		i;

	i = 0;
	while (i < 16)
	{
		fract[i].y_end = 50 * (i + 1);
		fract[i].y_start = fract[i].y_end - 50;
		fract[i].zoom = d->zoom;
		fract[i].move_x = d->move_x;
		fract[i].move_y = d->move_y;
		fract[i].iter = d->iter;
		fract[i].color_scheme = d->color_scheme;
		fract[i].d = d;
		pthread_create(&(thread[i]), NULL, burning_ship_f, (void *)&(fract[i]));
		i++;
	}
	i = 0;
	while (i < 16)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}