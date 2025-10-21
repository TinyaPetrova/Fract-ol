/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_motion_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 22:21:45 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 14:08:29 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_fractal_motion(int x, int y, t_fractal *fractal)
{
	if (fractal->type == JULIA)
		handle_julia_motion(x, y, fractal);
	else if (fractal->type == SPIDER)
		handle_spider_motion(x, y, fractal);
	else if (fractal->type == MANDELBROT)
		handle_mandelbrot_motion(x, y, fractal);
	else if (fractal->type == BURNING_SHIP)
		handle_ship_motion(x, y, fractal);
}

void	handle_julia_motion(int x, int y, t_fractal *fractal)
{
	t_range	from;
	t_range	to;

	from.min = 0;
	to.min = -2.0;
	to.max = 2.0;
	from.max = WIDTH;
	fractal->julia_re = map(x, from, to);
	from.max = HEIGHT;
	fractal->julia_im = map(y, from, to);
	fractal->needs_redraw = 1;
}

void	handle_spider_motion(int x, int y, t_fractal *fractal)
{
	t_range	from;
	t_range	to;

	from.min = 0;
	to.min = -2.0;
	to.max = 2.0;
	from.max = WIDTH;
	fractal->spider_re = map(x, from, to);
	from.max = HEIGHT;
	fractal->spider_im = map(y, from, to);
	fractal->needs_redraw = 1;
}

void	handle_mandelbrot_motion(int x, int y, t_fractal *fractal)
{
	t_range	from;
	t_range	to;

	from.min = 0;
	to.min = -2.0;
	to.max = 2.0;
	from.max = WIDTH;
	fractal->offset_x = map(x, from, to);
	from.max = HEIGHT;
	fractal->offset_y = map(y, from, to);
	fractal->needs_redraw = 1;
}

void	handle_ship_motion(int x, int y, t_fractal *fractal)
{
	t_range	from;
	t_range	to;

	from.min = 0;
	to.min = -2.0;
	to.max = 2.0;
	from.max = WIDTH;
	fractal->ship_cre = map(x, from, to);
	from.max = HEIGHT;
	fractal->ship_cim = map(y, from, to);
	fractal->needs_redraw = 1;
}
