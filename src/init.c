/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:01:57 by joao-pol          #+#    #+#             */
/*   Updated: 2024/09/07 12:36:28 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_mallerr(void)
{
	perror("Malloc Error");
	exit(2);
}

static void	ft_data_init(t_vars *vars)
{
	vars->iter = (t_limit){.min = 0, .max = 42};
	vars->scale = 1.0;
	vars->track_mouse = 0;
	vars->pointer = 0;
	vars->offset_x = 0.0;
	vars->offset_y = 0.0;
	vars->color = (t_limit){.min = 0x0f0f00, .max = EGGSHELL};
	vars->winlim_x = (t_limit){.min = 0.0, .max = IMG_WIDTH};
	vars->winlim_y = (t_limit){.min = 0.0, .max = IMG_HEIGHT};
	vars->mandellim_x = (t_limit){.min = -2.0, .max = 2.0};
	vars->mandellim_y = (t_limit){.min = -2.0, .max = 2.0};
	vars->julia_change = 0;
}

static void	ft_mlx_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		ft_mallerr();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, vars->name);
	if (vars->win == NULL)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(2);
	}
	vars->img = (t_img *)malloc(sizeof(t_img));
	if (!vars->img)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit (2);
	}
	vars->img->img = mlx_new_image(vars->mlx, IMG_WIDTH, IMG_HEIGHT);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel, &vars->img->size_line,
			&vars->img->endian);
}

static void	ft_events_init(t_vars *vars)
{
	mlx_hook(vars->win, KeyPress, KeyPressMask, ft_key, vars);
	mlx_hook(vars->win, ButtonPress, ButtonPressMask, ft_mouse, vars);
	mlx_hook(vars->win, DestroyNotify, StructureNotifyMask, ft_close,
		vars);
	mlx_hook(vars->win, MotionNotify, PointerMotionMask, ft_julia, vars);
	ft_sync(vars);
}

int	ft_setup(t_vars *vars)
{
	ft_mlx_init(vars);
	ft_data_init(vars);
	ft_events_init(vars);
	return (0);
}
