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

void	mlx_data_init(t_mlx *d)
{
	d->zoom = 0.0035;
	d->move_x = 0;
	d->move_y = 0;
	d->iter = ITERS;
	d->tmp_cr = 0;
	d->tmp_ci = 0.8;
}

int		choice_check(t_mlx *d, char *str)
{
	if (ft_strequ("Mandelbrot", str) || ft_strequ("M", str))
		d->fract_type = 1;
	else if (ft_strequ("Julia", str) || ft_strequ("J", str))
		d->fract_type = 2;
	else if (ft_strequ("Burnship", str) || ft_strequ("B", str))
		d->fract_type = 3;
	else
		d->fract_type = 0;
	return (d->fract_type);
}

void	fractal_init(t_mlx *d)
{
	d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->pixs = mlx_get_data_addr(d->img, &(d->bpp), &(d->s_line), &(d->endian));
	if (d->fract_type == M)
		p_tread_init(d);
	else if (d->fract_type == J)
		p_tread_init_j(d);
	else if (d->fract_type == B)
		p_tread_init_b(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

int 	expose_hook(t_mlx *d)
{
	fractal_init(d);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	*d;

	d = ft_memalloc(sizeof(t_mlx));
	if (argc == 2 && (choice_check(d, argv[1]) != 0))
	{
		d->mlx = mlx_init();
		d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "Fractol");
		mlx_data_init(d);
		mlx_expose_hook(d->win, expose_hook, d);
		mlx_hook(d->win, 2, 5, key_hook, d);
		mlx_hook(d->win, 6, 1L << 6, motion_hook, d);
		mlx_mouse_hook(d->win, mouse_hook, d);
		mlx_loop(d->mlx);
	}
	ft_error("usage: ./fractol (Julia / Mandelbrot)\n");
	return (0);
}

