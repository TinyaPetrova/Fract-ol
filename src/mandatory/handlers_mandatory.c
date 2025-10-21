/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_mandatory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:31:13 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 16:43:48 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse_m(int button, int x, int y, t_fractal *fractal)
{
	double	zoom_factor;

	(void)x;
	(void)y;
	zoom_factor = 1.2;
	if (button == MOUSE_WHEEL_UP)
	{
		fractal->zoom *= zoom_factor;
		draw_fractal_m(fractal);
	}

