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

void 	ft_draw(int x, int y, int iter, t_mlx *d)
{
	int a;
	int r;
	int g;
	int b;
	double cont_index;

    // a = (y * d->s_line / 4 + x) * 4;
    a = (x * (d->bpp / 8)) + (y * d->s_line);
    cont_index = (iter + 1) - (1 / d->z);
    d->pixs[a] = sin(0.016 * cont_index + 4 + 3) * 235 + 20;
    d->pixs[a + 1] = sin(0.013 * cont_index + 2 + 3) * 235 + 20;
    d->pixs[a + 2] = sin(0.01 * cont_index + 1 + 3) * 235 + 20;
    // d->pixs[a] = 255;
    // d->pixs[++a] = 255;
    // d->pixs[++a] = 255;
}

void	mlx_data_init(t_mlx *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "Fractol");
	d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->pixs = mlx_get_data_addr(d->img, &(d->bpp), &(d->s_line), &(d->endian));
	d->zoom = 0.004;
}

int		ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_mlx	*d;
	t_fract	*fract;
	d = ft_memalloc(sizeof(t_mlx));
	fract = ft_memalloc(sizeof(t_fract));
	d->fract = fract;
	if (argc != 1 || argv[0] || !d || !fract)
	{
			mlx_data_init(d);
			fractal_init(100, d);
			mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
			// mlx_expose_hook(d->win, expose_hook, d);
			// mlx_key_hook(d->win, key_hook, d);
			mlx_loop(d->mlx);
	}
	ft_error("usage: ./fractol (Julia / Mandelbrot)\n");
	return (0);
}

