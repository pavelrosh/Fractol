/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:55:59 by proshchy          #+#    #+#             */
/*   Updated: 2018/02/23 13:56:02 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "mlx.h"

# define WIDTH 1280
# define HEIGHT 720
# define MAX_ELEMS 92160


typedef struct 	s_coord
{
	double 		x;
	double 		y;
}				t_coord;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	char		*img;
	char		*pix;
	int			s_line;
	int			bpp;
	int			endian;
	char		*pixs;
	t_coord		*c;
}				t_mlx;


#endif
