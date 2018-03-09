/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:55:59 by proshchy          #+#    #+#             */
/*   Updated: 2018/03/09 18:11:07 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <pthread.h>

# include "../libft/libft.h"
# include "mlx.h"

# define WIDTH 1200
# define HEIGHT 800
# define MAX_ELEMS 92160
# define ZOOM 0.004
# define OFF_X -0.5
# define OFF_Y 0
# define M 1
# define J 2
# define B 3
# define N 4
# define C 5
# define ITERS 51
# define MAX_KEY 23

# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define INCR 69
# define DECR 78
# define SCHEME 49
# define PSX 106
# define PSY 79
# define NSX 64
# define NSY 80
# define DECR_I 75
# define INCR_I 67
# define MOUSE_UP 5
# define MOUSE_DOWN 4

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
	int			iter;
	int			fract_type;
	int			color_scheme;
	double		tmp_cr;
	double		tmp_ci;
}				t_mlx;

typedef struct	s_fract
{
	double		c_r;
	double		c_i;
	double		c_rr;
	double		c_ii;
	double		tmp_cr;
	double		tmp_ci;
	double		move_x;
	double		move_y;
	double		zoom;
	double		z;
	int			n;
	int			x;
	int			y_start;
	int			y_end;
	int			iter;
	int			fract_type;
	int			color_scheme;
	t_mlx		*d;
}				t_fract;

typedef struct	s_color
{
	double		freq;
	int			phase;
	int			width;
	int			center;
}				t_color;

void			*mandelbrot_f(void *args);
void			*julia_f(void *args);
void			*burning_ship_f(void *args);
void			*newton_f(void *args);
void			*infin_cube_f(void *args);
void			ft_draw(t_fract *fract, t_mlx *d);
void			mlx_data_init(t_mlx *d);
int				key_hook(int key, t_mlx *d);
int				ft_error(char *str);
int				expose_hook(t_mlx *d);
int				motion_hook(int x, int y, t_mlx *d);
int				mouse_hook(int key, int x, int y, t_mlx *d);
void			mlx_data_init(t_mlx *d);
void			p_tread_init(t_mlx *d);
void			p_tread_init_j(t_mlx *d);
void			p_tread_init_b(t_mlx *d);
void			p_tread_init_n(t_mlx *d);
void			p_tread_init_infc(t_mlx *d);
#endif
