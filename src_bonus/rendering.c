/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 00:09:45 by pracksaw          #+#    #+#             */
/*   Updated: 2024/09/07 13:06:16 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	fractal_render(double x, double y, t_vars *vars)
{
	t_point	z;
	t_point	c;
	int		color;
	int		iter;

	iter = 0;
	c = (t_point){.x = 0, .y = 0};
	z.x = (ft_convert(x, vars->mandellim_x, vars->winlim_x)
			* vars->scale) + vars->offset_x;
	z.y = (ft_convert(y, vars->mandellim_y, vars->winlim_y)
			* vars->scale) + vars->offset_y;
	ft_choose_fractal(&z, &c, vars);
	while (iter++ < vars->iter.max)
	{
		z = ft_sumsquare(z, c);
		if ((z.x * z.x) * (z.y * z.y) > 4)
		{
			color = ft_convert(iter, vars->color, vars->iter);
			ft_neo_pixel(vars->img, x, y, color);
			return ;
		}
	}
}

void	ft_renderimage(t_vars *vars)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < IMG_HEIGHT)
	{
		x = 0;
		while (x < IMG_WIDTH)
		{
			fractal_render(x, y, vars);
			x += 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img,
		(WIN_WIDTH - IMG_WIDTH) / 2, (WIN_HEIGHT - IMG_HEIGHT) / 2);
}

void	ft_choose_fractal(t_point *z, t_point *c, t_vars *vars)
{
	if (!ft_strncmp(vars->name, "julia", 2))
		*c = (t_point){.x = vars->julia_x, .y = vars->julia_y};
	else
		*c = (t_point){.x = z->x, .y = z->y};
}
