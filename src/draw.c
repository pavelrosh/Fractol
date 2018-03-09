/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:42:05 by proshchy          #+#    #+#             */
/*   Updated: 2018/03/09 18:08:26 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_color		*color_init(t_fract *fract)
{
	t_color *color;

	if (!(color = malloc(sizeof(t_color))))
	{
		ft_error("malloc failed in color_init()\n");
		return (0);
	}
	color->phase = 1;
	color->width = 70;
	color->center = 185;
	if (fract->color_scheme == 2)
	{
		color->phase = 3;
		color->width = 235;
		color->center = 20;
	}
	if (fract->color_scheme == 3)
	{
		color->phase = 2;
		color->width = 110;
		color->center = 135;
	}
	return (color);
}

void		ft_draw(t_fract *fract, t_mlx *d)
{
	int		a;
	double	cont_index;
	t_color	*color;

	color = color_init(fract);
	a = (fract->x * (d->bpp / 8)) + (fract->y_start * d->s_line);
	cont_index = (fract->n + 1) - (1 / fract->z);
	color->freq = M_PI * 2 / fract->iter;
	d->pixs[a] = sin(color->freq * cont_index + 4 + color->phase)
	* color->width + color->center;
	d->pixs[++a] = sin(color->freq * cont_index + 2 + color->phase)
	* color->width + color->center;
	d->pixs[++a] = sin(color->freq * cont_index + 1 + color->phase)
	* color->width + color->center;
	free(color);
}
