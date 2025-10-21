/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print_mandatory.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:47:04 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 15:21:53 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage_m(void)
{
	write(1, "use like this: ./fractol [fractal] [options]\n", 38);
	write(1, "\navailable fractals:\n", 21);
	write(1, "  mandelbrot\n", 13);
	write(1, "  julia [real] [imaginary]  (range: -2.0 to 2.0)\n", 49);
	write(1, "\ncontrols:\n", 11);
	write(1, "  mouse wheel: zoom in/out\n", 27);
	write(1, "  esc: exit\n", 12);
}
