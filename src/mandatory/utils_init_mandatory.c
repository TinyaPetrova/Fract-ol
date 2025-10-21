/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init_mandatory.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:30:00 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 16:37:36 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal_base(t_fractal *f)
{
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->max_iter = MAX_ITER;
	f->julia_re = -0.7;
	f->julia_im = 0.27015;
	f->needs_redraw = 0;
	f->palette = 1;
	f->mouse_lock = 0;
}

void	init_julia_fractal(t_fractal *f, char **argv, int argc)
{
	f->type = JULIA;
	if (argc == 4)
	{
		f->julia_re = ft_atof(argv[2]);
		f->julia_im = ft_atof(argv[3]);
	}
}

int	close_exit_m(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
	return (0);
}

void	setup_hooks_m(t_fractal *fractal)
{
	mlx_hook(fractal->win, CLOSE_EVENT, NO_MASK, close_exit_m, fractal);
	mlx_key_hook(fractal->win, handle_key_m, fractal);
	mlx_mouse_hook(fractal->win, handle_mouse_m, fractal);
}

void	init_fractal_m(t_fractal *f, char **argv, int argc)
{
	init_fractal_base(f);
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		f->type = MANDELBROT;
	else if (!ft_strncmp(argv[1], "julia", 5))
		init_julia_fractal(f, argv, argc);
	else
		exit(1);
}
