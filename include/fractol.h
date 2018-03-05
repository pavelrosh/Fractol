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
# include "libft.h"
# include "mlx.h"

# define WIDTH 1200
# define HEIGHT 800
# define MAX_ELEMS 92160
# define ZOOM 0.004//0.9 // * decr || / incr size
# define OFF_X -0.5
# define OFF_Y 0
# define M 1
# define J 2
# define ITERS 100

# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define X_UP 91
# define X_DOWN 84
# define Y_RIGHT 88
# define Y_LEFT 86
# define Z_LEFT 89
# define Z_RIGHT 92
# define INCR 69
# define DECR 78
# define CENTER 49
# define PSX 106
# define PSY 79
# define NSX 64
# define NSY 80
# define STEP 50
 
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
	double		move_x;
	double		move_y;
	double		zoom;
	double		z;
	int 		fract_type;
	t_fract		*mandelbrot;
	t_fract		*julia;
}				t_mlx;

void			mandelbrot_f(int iter, t_mlx *d, t_fract *fract);
void			julia_f(int iter, t_mlx *d, t_fract *fract);
void			ft_draw(int x, int y, int iter, t_mlx *d);
void			mlx_data_init(t_mlx *d);
int 			key_hook(int key, t_mlx *d);
int				ft_error(char *str);
int 			expose_hook(t_mlx *d);
#endif


























