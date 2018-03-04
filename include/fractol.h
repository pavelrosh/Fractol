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
// # include "libft/libft.h"
# include "libft.h"
# include "mlx.h"

# define WIDTH 1200
# define HEIGHT 600
# define MAX_ELEMS 92160
# define ZOOM 1//0.9 // * decr || / incr size
# define OFF_X 0//-0.7
# define OFF_Y 0
 
typedef struct 	s_coord
{
	double 		x;
	double 		y;
}				t_coord;

typedef struct 	s_fract
{
	double		c_r;
	double		c_i;
	double		c_rr;
	double		c_ii;
	double		tmp_cr;
	double		tmp_ci;
	int 		n;
	int 		x;
	int 		y;
}				t_fract;

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
	double		zoom;
	double		move_x;
	double		move_y;
	double		z;
	t_fract		*fract;
}				t_mlx;

void			fractal_init(int iter, t_mlx *d);
void			ft_draw(int x, int y, int iter, t_mlx *d);
void			mlx_data_init(t_mlx *d);
#endif
