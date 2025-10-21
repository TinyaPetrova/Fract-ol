/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:36:33 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 16:30:04 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse_b(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	zoom_factor = 1.1;
	mouse_re = get_mouse_real(x, fractal);
	mouse_im = get_mouse_imag(y, fractal);
	if (button == ZOOM_IN)
		zoom_in(fractal, mouse_re, mouse_im, zoom_factor);
	else if (button == ZOOM_OUT)
		zoom_out(fractal, mouse_re, mouse_im, zoom_factor);
	adjust_iterations_for_zoom(fractal);
	fractal->needs_redraw = 1;
	return (0);
}

int	handle_key_b(int key, t_fractal *fractal)
{
	if (key == ESC_KEY)
		close_exit_b(fractal);
	else if (handle_movement_keys(key, fractal))
		fractal->needs_redraw = 1;
	else if (handle_iteration_keys(key, fractal))
		fractal->needs_redraw = 1;
	else if (handle_special_keys(key, fractal))
		fractal->needs_redraw = 1;
	else
		return (0);
	return (0);
}

int	handle_motion(int x, int y, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (!fractal->mouse_lock)
	{
		handle_fractal_motion(x, y, fractal);
	}
	return (0);
}

double	get_mouse_real(int x, t_fractal *fractal)
{
	t_range	from;
	t_range	to;

	from.min = 0;
	from.max = WIDTH;
	to.min = -2.0 / fractal->zoom + fractal->offset_x;
	to.max = 2.0 / fractal->zoom + fractal->offset_x;
	return (map(x, from, to));
}

double	get_mouse_imag(int y, t_fractal *fractal)
{
	t_range	from;
	t_range	to;

	from.min = 0;
	from.max = HEIGHT;
	to.min = -2.0 / fractal->zoom + fractal->offset_y;
	to.max = 2.0 / fractal->zoom + fractal->offset_y;
	return (map(y, from, to));
}
