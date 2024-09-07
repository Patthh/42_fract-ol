/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:56:15 by pracksaw          #+#    #+#             */
/*   Updated: 2024/09/07 19:32:38 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_key(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape || keysym == XK_q)
		ft_close(vars);
	else if (keysym == XK_Left)
		vars->offset_x -= (0.3 * vars->scale);
	else if (keysym == XK_Right)
		vars->offset_x += (0.3 * vars->scale);
	else if (keysym == XK_Up)
		vars->offset_y -= (0.3 * vars->scale);
	else if (keysym == XK_Down)
		vars->offset_y += (0.3 * vars->scale);
	else if (keysym == XK_plus || keysym == 65451 || keysym == XK_P)
		vars->iter.max += 1;
	else if ((keysym == XK_minus || keysym == 65453) && vars->iter.max > 1)
		vars->iter.max -= 1;
	else if (keysym == XK_r)
	{
		vars->offset_x = 0;
		vars->offset_y = 0;
		vars->scale = 1;
		vars->iter.max = 42;
	}
	else if (keysym == XK_j)
		vars->julia_change = !vars->julia_change;
	return (0);
}

int	ft_mouse(int mousecode, int x, int y, t_vars *vars)
{
	if (mousecode == 1)
		vars->track_mouse = !vars->track_mouse;
	else if (mousecode == 2)
		vars->pointer = !vars->pointer;
	if (mousecode == 4)
	{
		vars->scale *= 0.9;
		if (vars->track_mouse)
		{
			vars->offset_x += (0.75 * (x - (double)IMG_WIDTH / 2)
					/ IMG_WIDTH * vars->scale);
			vars->offset_y += (0.75 * (y - (double)IMG_HEIGHT / 2)
					/ IMG_HEIGHT * vars->scale);
		}
	}
	else if (mousecode == 5)
		vars->scale /= 0.9;
	if (vars->julia_change)
		mlx_hook(vars->win, MotionNotify, PointerMotionMask, ft_julia, vars);
	ft_sync(vars);
	return (0);
}

int	ft_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->img);
	free(vars->mlx);
	exit (0);
}

int	ft_julia(int x, int y, t_vars *vars)
{
	if (!ft_strncmp(vars->name, "julia", 5) && vars->julia_change)
	{
		vars->julia_x = (ft_convert(x, vars->mandellim_x, vars->winlim_x)
				* vars->scale) + vars->offset_x;
		vars->julia_y = (ft_convert(y, vars->mandellim_y, vars->winlim_y)
				* vars->scale) + vars->offset_y;
		ft_sync(vars);
	}
	return (0);
}

int	ft_sync(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->img);
	vars->img->img = mlx_new_image(vars->mlx, IMG_WIDTH, IMG_HEIGHT);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel,
			&vars->img->size_line, &vars->img->endian);
	if (vars->pointer)
		ft_neo_pixel(vars->img, IMG_WIDTH / 2, IMG_HEIGHT / 2, WHITE);
	ft_renderimage(vars);
	return (0);
}
