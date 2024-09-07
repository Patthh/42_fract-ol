/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:15:42 by pracksaw          #+#    #+#             */
/*   Updated: 2024/09/07 19:53:08 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/keysym.h>
# include <X11/X.h>
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# define WHITE       0xFFFFFF
# define BLACK       0x000000
# define EGGSHELL    0xFFE5B4
# define ERR_INVALID_ARG "Invalid Argument"
# define ERR_MSG_INPUT "Usage :\n\t\"./fractol julia <R> <i>\"\
	\n\t\n\t\"./fractol mandelbrot\"\n\
	\n-0.4 + 0.6i || 0.285 + 0.0i || 0.285 + 0.01i\n\
	\n 0.45 + 0.1428i || -0.70176 - 0.3842i || -0.835 - 0.2321i \n\
	\n -1.77029598415682387070596815828735774662104581 -0.005852576008784477443909236300355828076899285495 \n\
	\n -0.8 + 0.156i || -0.7269 + 0.1889i ||  0.35 + 0.35i\n"
# define ERR_MSG_MLX "Error in MLX"
# define WIN_HEIGHT 360
# define WIN_WIDTH 720
# define IMG_HEIGHT 360
# define IMG_WIDTH 720
# define PRECISION 7

typedef struct s_limit
{
	double	min;
	double	max;
}	t_limit;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_vars
{
	char		*program;
	char		*name;
	void		*mlx;
	void		*win;
	t_limit		winlim_x;
	t_limit		winlim_y;
	t_limit		mandellim_x;
	t_limit		mandellim_y;
	t_limit		color;
	t_limit		iter;
	t_img		*img;
	double		scale;
	double		offset_x;
	double		offset_y;
	double		julia_x;
	double		julia_y;
	int			julia_change;
	int			track_mouse;
	int			pointer;
}				t_vars;

int		ft_setup(t_vars *vars);
int		ft_key(int keycode, t_vars *vars);
int		ft_mouse(int mousecode, int x, int y, t_vars *vars);
int		ft_close(t_vars *vars);
int		ft_julia(int x, int y, t_vars *vars);
void	ft_neo_pixel(t_img *data, int x, int y, int color);
int		ft_drawimage(t_vars *vars);
void	ft_choose_fractal(t_point *z, t_point *c, t_vars *vars);
void	ft_renderimage(t_vars *vars);
int		ft_sync(t_vars *vars);
t_point	ft_calc(t_point z, t_point c, t_vars *vars);
double	ft_convert(double i, t_limit new, t_limit old);
double	ft_atof(char *str);
t_point	ft_sum(t_point z1, t_point z2);
t_point	ft_square(t_point z);
t_point	ft_sumsquare(t_point z, t_point c);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_isdigit(char *str);

#endif
