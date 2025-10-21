/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_key_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 22:20:19 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 14:08:56 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_movement_keys(int key, t_fractal *fractal)
{
	double	move_factor;

	move_factor = MOVE_STEP / fractal->zoom;
	if (key == ARROW_UP || key == KEY_W)
		fractal->offset_y += move_factor;
	else if (key == ARROW_DOWN || key == KEY_S)
		fractal->offset_y -= move_factor;
	else if (key == ARROW_LEFT || key == KEY_A)
		fractal->offset_x += move_factor;
	else if (key == ARROW_RIGHT || key == KEY_D)
		fractal->offset_x -= move_factor;
	else
		return (0);
	return (1);
}

int	handle_iteration_keys(int key, t_fractal *fractal)
{
	if (key == PLUS_KEY || key == EQUAL_KEY)
	{
		fractal->max_iter += 10;
		if (fractal->max_iter > 1000)
			fractal->max_iter = 1000;
	}
	else if (key == MINUS_KEY || key == UNDERSCORE_KEY)
	{
		fractal->max_iter -= 10;
		if (fractal->max_iter < 10)
			fractal->max_iter = 10;
	}
	else
		return (0);
	return (1);
}

int	handle_special_keys(int key, t_fractal *fractal)
{
	if (key == C_KEY)
	{
		fractal->palette++;
		if (fractal->palette > 3)
			fractal->palette = 1;
	}
	else if (key == L_KEY)
		fractal->mouse_lock = !fractal->mouse_lock;
	else
		return (0);
	return (1);
}
