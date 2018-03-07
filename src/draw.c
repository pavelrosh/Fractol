/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:42:05 by proshchy          #+#    #+#             */
/*   Updated: 2018/03/05 13:42:06 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_color		*color_init(t_fract *fract, t_mlx *d)
{
	t_color *color;

	color = malloc(sizeof(t_color));
	color->phase = 1;
	color->width = 70;
	color->center = 185;
	if (d->color_scheme == 2)
	{
		color->phase = 3;
		color->width = 235;
		color->center = 20;
	}
	if (d->color_scheme == 3)
	{
		color->phase = 2;
		color->width = 110;
		color->center = 135;
	}
	return (color);
}

void 	ft_draw(t_fract *fract, t_mlx *d)
{
	int a;
	double cont_index;
	t_color *color;

	color = color_init(fract, d);
	a = (fract->x * (d->bpp / 8)) + (fract->y * d->s_line);
	cont_index = (fract->n + 1) - (1 / d->z);
	color->freq = M_PI * 2 / d->iter;
	d->pixs[a] = sin(color->freq * cont_index + 4 + color->phase) * color->width + color->center;
	d->pixs[++a] = sin(color->freq * cont_index + 2 + color->phase) * color->width + color->center;
	d->pixs[++a] = sin(color->freq * cont_index + 1 + color->phase) * color->width + color->center;
	free(color);
}