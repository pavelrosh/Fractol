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

void 	ft_draw(int x, int y, int iter, t_mlx *d)
{
	int a;
	int r;
	int g;
	int b;
	double cont_index;

    a = (x * (d->bpp / 8)) + (y * d->s_line);
    cont_index = (iter + 1) - (1 / d->z);
    d->pixs[a] = sin(0.016 * cont_index + 4 + 3) * 235 + 20;
    d->pixs[++a] = sin(0.013 * cont_index + 2 + 3) * 235 + 20;
    d->pixs[++a] = sin(0.01 * cont_index + 1 + 3) * 235 + 20;
}