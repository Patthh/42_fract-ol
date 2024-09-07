/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:34:37 by pracksaw          #+#    #+#             */
/*   Updated: 2024/09/07 19:46:19 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_dot(char *v1, char *v2);

static int	ft_check_errors(int argc, char *argv[])
{
	if ((!ft_strncmp(argv[1], "mandelbrot", 10) && argc == 2)
		|| (!ft_strncmp(argv[1], "julia", 5) && argc == 4))
		return (0);
	else
	{
		perror(ERR_MSG_INPUT);
		exit (1);
	}
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	vars.name = argv[1];
	vars.program = argv[0];
	ft_check_errors(argc, argv);
	if (!ft_strncmp("julia", vars.name, 5))
	{
		check_dot(argv[2], argv[3]);
		if (!ft_isdigit(argv[2]) || !ft_isdigit(argv[3]))
		{
			perror(ERR_INVALID_ARG);
			exit (1);
		}
		vars.julia_x = ft_atof(argv[2]);
		vars.julia_y = ft_atof(argv[3]);
	}
	ft_setup(&vars);
	ft_renderimage(&vars);
	mlx_loop(vars.mlx);
	return (0);
}

void	ft_neo_pixel(t_img *data, int x, int y, int color)
{
	char	*pxl;

	if (x < IMG_WIDTH && y < IMG_HEIGHT)
	{
		pxl = data->addr + (y * data->size_line + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

static void	check_dot(char *v1, char *v2)
{
	if (v1[0] == '.' || v2[0] == '.' )
	{
		perror(ERR_INVALID_ARG);
		exit (1);
	}
}
