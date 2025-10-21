/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:33:42 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 16:37:16 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal_base(t_fractal *f)
{
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->max_iter = 100;
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

int	close_exit_m(t_fractal *fractal)
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

	if (!validate_input_m(argc, argv))
	{
		print_usage_m();
		return (1);
	}
	init_fractal_m(&fractal, argv, argc);
	if (!init_mlx(&fractal))
		return (1);
	setup_hooks_m(&fractal);
	draw_fractal_m(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
