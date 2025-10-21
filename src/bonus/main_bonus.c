/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:37:22 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 16:37:46 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal_base(t_fractal *f)
{
	f->mouse_lock = 0;
	f->palette = 1;
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->max_iter = 100;
	f->needs_redraw = 1;
	f->ship_cre = -1.8;
	f->ship_cim = -0.5;
}

void	init_julia_fractal(t_fractal *f, char **argv, int argc)
{
	f->type = JULIA;
	if (argc == 4)
	{
		f->julia_re = ft_atof(argv[2]);
		f->julia_im = ft_atof(argv[3]);
	}
	else
	{
		f->julia_re = -0.8;
		f->julia_im = 0.156;
	}
}

void	init_spider_fractal(t_fractal *f, char **argv, int argc)
{
	f->type = SPIDER;
	if (argc == 4)
	{
		f->spider_re = ft_atof(argv[2]);
		f->spider_im = ft_atof(argv[3]);
	}
	else
	{
		f->spider_re = 0.7;
		f->spider_im = 0.1;
	}
}

int	close_exit_b(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (!validate_input_b(argc, argv))
	{
		print_usage_b();
		return (1);
	}
	init_fractal_b(&fractal, argv, argc);
	if (!init_mlx(&fractal))
		return (1);
	draw_fractal_b(&fractal);
	fractal.needs_redraw = 0;
	setup_hooks_b(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
