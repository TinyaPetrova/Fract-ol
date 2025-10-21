/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 22:33:29 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 16:37:36 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	idle_hook(t_fractal *fractal)
{
	if (fractal->needs_redraw)
	{
		draw_fractal_b(fractal);
		fractal->needs_redraw = 0;
	}
	return (0);
}

int	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		return (0);
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!fractal->win)
		return (0);
	fractal->img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img.img)
		return (0);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp,
			&fractal->img.length, &fractal->img.endian);
	return (1);
}

void	setup_hooks_b(t_fractal *fractal)
{
	mlx_hook(fractal->win, CLOSE_EVENT, NO_MASK, close_exit_b, fractal);
	mlx_key_hook(fractal->win, handle_key_b, fractal);
	mlx_mouse_hook(fractal->win, handle_mouse_b, fractal);
	mlx_loop_hook(fractal->mlx, idle_hook, fractal);
	mlx_hook(fractal->win, 6, 1L << 6, handle_motion, fractal);
}

void	init_fractal_b(t_fractal *f, char **argv, int argc)
{
	init_fractal_base(f);
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		f->type = MANDELBROT;
	else if (!ft_strncmp(argv[1], "julia", 5))
		init_julia_fractal(f, argv, argc);
	else if (!ft_strncmp(argv[1], "spider", 6))
		init_spider_fractal(f, argv, argc);
	else if (!ft_strncmp(argv[1], "burning_ship", 12))
		f->type = BURNING_SHIP;
	else
		exit(1);
}
