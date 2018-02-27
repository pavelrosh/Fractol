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

#include "fractol.h"

// void	map(t_mlx *d)
// {
// 	double	w_p;
// 	double	h_p;

// 	w_p = d->c.x / 12.5;
// 	h_p = d->c.y / 7.2;
// 	if (w_p < 50)
// 		d->c.x = -0.04 * w_p;
// 	else
// 		d->c.x = 0.04 * w_p;
// 	if (h_p < 50)
// 		d-c.y = -0.04 * h_p;
// 	else
// 		d->c.y = 0.04 * h_p;
// }

void	init(t_mlx *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "Fractol");
	d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->pixs = mlx_get_data_addr(d->img, &(d->bpp), &(d->s_line), &(d->endian));
}

// void	mandelbrot_f(int iter, t_mlx *d)
// {
// 	double a;
// 	double b;
// 	double ca;
// 	double cb;
// 	int n;

// 	n = 0;
// 	while (d->c[n].x < WIDTH)
// 	{
// 		a = map(d->c[n].x);
// 		while (y < HEIGHT)
// 		{
// 			while (n < iter)
// 			{
// 				aa = a * a - b * b;
// 				bb = 2 * a * b;
// 				a = aa;
// 				b = bb;
// 				if ((a + b) > 16)
// 					break ;
// 			}
// 		}
// 	}
// }

int		ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

int		main(int argc, char **argv)
{
	int n;

	t_mlx	*d;
	t_coord	c[MAX_ELEMS];
	d = ft_memalloc(sizeof(t_mlx));
	d->c = c;
	n = 0;
	if (argc != 1 || argv[0])
	{
			init(d);
			// while (n < MAX_ELEMS)
			// {
			// 	d->pixs[n] = 0xFFFFFF;
			// 	n++;
			// }
			mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
			// printf("elems = %c\n", d->pixs[0]);
			// printf("%#010x\n", d->pixs[]);
			mlx_loop(d->mlx);
			// fractol(100, d);	
	}
	ft_error("usage: ./fractol (Julia / Mandelbrot)\n");
	return (0);
}

