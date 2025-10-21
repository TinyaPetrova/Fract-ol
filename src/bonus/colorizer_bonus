/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorizer_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:13:50 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 15:12:46 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_wave(double x)
{
	double	temp;

	temp = x * 0.159155;
	temp = temp - (int)temp;
	if (temp < 0)
		temp += 1.0;
	if (temp < 0.5)
		return (4.0 * temp - 1.0);
	else
		return (3.0 - 4.0 * temp);
}

static int	get_red(int palette, double t)
{
	if (palette == 1)
		return ((int)(9 * (1 - t) * t * t * t * 255));
	else if (palette == 2)
		return ((int)(255 * (0.5 + 0.5 * ft_wave(5.0 * t + 0.0))));
	else if (palette == 3)
		return ((int)(255 * t));
	else
		return ((int)(255 * t));
}

static int	get_green(int palette, double t)
{
	if (palette == 1)
		return ((int)(15 * (1 - t) * (1 - t) * t * t * 255));
	else if (palette == 2)
		return ((int)(255 * (0.3 + 0.3 * ft_wave(3.0 * t + 2.0))));
	else if (palette == 3)
		return ((int)(128 * t * t));
	else
		return ((int)(255 * t));
}

static int	get_blue(int palette, double t)
{
	if (palette == 1)
		return ((int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255));
	else if (palette == 2)
		return ((int)(255 * (0.7 + 0.3 * ft_wave(4.0 * t + 4.0))));
	else if (palette == 3)
		return ((int)(32 * sqrt(t)));
	else
		return ((int)(255 * t));
}

int	colorize_b(int iter, int max_iter, int palette)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / max_iter;
	r = get_red(palette, t);
	g = get_green(palette, t);
	b = get_blue(palette, t);
	return ((r << 16) | (g << 8) | b);
}
