/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init_mandatory.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:31:42 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 16:37:10 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	setup_hooks_m(t_fractal *fractal)
{
	mlx_hook(fractal->win, 17, 0, close_exit_m, fractal);
	mlx_key_hook(fractal->win, handle_key_m, fractal);
	mlx_mouse_hook(fractal->win, handle_mouse_m, fractal);
}

void	init_fractal_m(t_fractal *f, char **argv, int argc)
{
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->max_iter = 100;
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		f->type = MANDELBROT;
	else if (!ft_strncmp(argv[1], "julia", 5))
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
}
