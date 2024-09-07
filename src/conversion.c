/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:35:11 by pracksaw          #+#    #+#             */
/*   Updated: 2024/09/07 19:40:52 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_convert(double i, t_limit new, t_limit old)
{
	return ((new.max - new.min) *(i - old.min) / (old.max - old.min) + new.min);
}

t_point	ft_sumsquare(t_point z, t_point c)
{
	t_point	square;
	t_point	sum;

	square.x = (z.x * z.x) - (z.y * z.y);
	square.y = 2 * (z.x * z.y);
	sum.x = square.x + c.x;
	sum.y = square.y + c.y;
	return (sum);
}

static int	ft_isdione(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

double	ft_atof(char *str)
{
	double	dec;
	double	frac;
	long	integer;
	int		neg;

	neg = 1;
	integer = 0;
	frac = 0;
	dec = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			neg = -1;
	while (ft_isdione(*str) && *str != '.')
		integer = (integer * 10) + (*str++ - 48);
	if (*str == '.')
	{
		str++;
		while (*str)
		{
			dec /= 10;
			frac = frac + (*str++ - 48) * dec;
		}
	}
	return ((integer + frac) * neg);
}
