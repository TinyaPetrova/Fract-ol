/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_zoom_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 22:22:37 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 14:08:08 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_fractal *f, double mouse_re, double mouse_im, double factor)
{
	f->zoom *= factor;
	f->offset_x = mouse_re - (mouse_re - f->offset_x) / factor;
	f->offset_y = mouse_im - (mouse_im - f->offset_y) / factor;
}

void	zoom_out(t_fractal *f, double mouse_re, double mouse_im, double factor)
{
	f->zoom /= factor;
	f->offset_x = mouse_re - (mouse_re - f->offset_x) * (1.0 / factor);
	f->offset_y = mouse_im - (mouse_im - f->offset_y) * (1.0 / factor);
}

void	adjust_iterations_for_zoom(t_fractal *fractal)
{
	if (fractal->zoom > 1000.0)
		fractal->max_iter = 300;
	else if (fractal->zoom > 500.0)
		fractal->max_iter = 250;
	else if (fractal->zoom > 100.0)
		fractal->max_iter = 200;
	else if (fractal->zoom > 20.0)
		fractal->max_iter = 150;
	else if (fractal->zoom > 5.0)
		fractal->max_iter = 120;
	else
		fractal->max_iter = 100;
}
