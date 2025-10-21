/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 22:32:27 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 15:10:48 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_basic_usage(void)
{
	write(1, "use like this: ./fractol [fractal] [options]\n", 46);
	write(1, "\navailable fractals + options:\n", 31);
	write(1, "  mandelbrot\n", 13);
	write(1, "  julia [real] [imaginary]        (range: -2.0 to 2.0)\n", 55);
	write(1, "  spider [real] [imaginary]       (range: -2.0 to 2.0)\n", 55);
	write(1, "  burning_ship\n", 15);
}

void static	print_controls(void)
{
	write(1, "\ncontrols:\n", 11);
	write(1, "  mouse wheel: zoom in/out\n", 27);
	write(1, "  arrow keys: move around\n", 26);
	write(1, "  esc: exit\n", 12);
}

void static	print_features(void)
{
	write(1, "\nspecial features:\n", 19);
	write(1, "  for Julia/Spider/Ship: move mouse to change parameters\n", 57);
	write(1, "  for Mandelbrot: move mouse just to pan\n", 41);
	write(1, "  +/-: increase/decrease iterations\n", 36);
	write(1, "  c-key: change color palette\n", 30);
	write(1, "  l-key: lock/unlock mouse parameter control\n", 45);
	write(1, "\n", 1);
}

void	print_usage_b(void)
{
	print_basic_usage();
	print_controls();
	print_features();
}
