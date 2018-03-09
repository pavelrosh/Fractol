/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:44:18 by proshchy          #+#    #+#             */
/*   Updated: 2018/03/09 17:55:34 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	calc_newton(t_fract *fract, int iter)
{
	fract->n = 0;
	while (fract->n < iter && fract->c_rr > 0.000001)
	{
		fract->tmp_cr = fract->c_r;
		fract->tmp_ci = fract->c_i;
		fract->c_rr = (fract->c_r * fract->c_r + fract->c_i * fract->c_i)
		* (fract->c_r * fract->c_r + fract->c_i * fract->c_i);
		fract->c_r = (2 * fract->c_r * fract->c_rr + fract->c_r
			* fract->c_r - fract->c_i * fract->c_i) / (3.0 * fract->c_rr);
		fract->c_i = (2 * fract->c_i * (fract->c_rr - fract->tmp_cr))
		/ (3.0 * fract->c_rr);
		fract->c_rr = (fract->c_r - fract->tmp_cr) *
			(fract->c_r - fract->tmp_cr)
		+ (fract->c_i - fract->tmp_ci) * (fract->c_i - fract->tmp_ci);
		fract->n++;
	}
}

void	*newton_f(void *args)
{
	t_fract *fract;

	fract = (t_fract *)args;
	while (fract->y_start < fract->y_end)
	{
		fract->x = 0;
		while (fract->x < WIDTH)
		{
			fract->c_r = (fract->x - WIDTH / 2.0) * fract->zoom + fract->move_x;
			fract->c_i = (fract->y_start - HEIGHT / 2.0) * fract->zoom +
				fract->move_y;
			fract->c_rr = 3.0;
			calc_newton(fract, fract->iter);
			fract->z = fract->c_r * fract->c_r + fract->c_i * fract->c_i;
			if (fract->n < fract->iter)
				ft_draw(fract, fract->d);
			fract->x++;
		}
		fract->y_start++;
	}
	pthread_exit(0);
}

void	p_tread_init_n(t_mlx *d)
{
	pthread_t	thread[16];
	t_fract		fract[16];
	int			i;

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
		pthread_create(&(thread[i]), NULL, newton_f, (void *)&(fract[i]));
		i++;
	}
	i = 0;
	while (i < 16)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}
