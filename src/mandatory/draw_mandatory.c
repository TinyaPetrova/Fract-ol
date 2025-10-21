/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:30:07 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 15:17:48 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->length + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

static void	init_draw_params(t_draw_params *d, t_fractal *f)
{
	d->step_x = 4.0 / (f->zoom * WIDTH);
	d->step_y = 4.0 / (f->zoom * HEIGHT);
	d->min_x = -2.0 / f->zoom + f->offset_x;
	d->min_y = -2.0 / f->zoom + f->offset_y;
}

static int	calculate_fractal_iter(t_fractal *f, t_complex_params *p)
{
	if (f->type == MANDELBROT)
		return (mandelbrot(p->x, p->y, p->max_iter));
	else if (f->type == JULIA)
	{
		p->cre = f->julia_re;
		p->cim = f->julia_im;
		return (julia(*p));
	}
	return (0);
}

void	draw_fractal_m(t_fractal *f)
{
	t_draw_params		d;
	t_complex_params	p;
	int					iter;

	init_draw_params(&d, f);
	p.max_iter = f->max_iter;
	d.y = 0;
	while (d.y < HEIGHT)
	{
		p.y = d.min_y + d.y * d.step_y;
		d.x = 0;
		while (d.x < WIDTH)
		{
			p.x = d.min_x + d.x * d.step_x;
			iter = calculate_fractal_iter(f, &p);
			put_pixel(&f->img, d.x, d.y, colorize_m(iter, f->max_iter));
			d.x++;
		}
		d.y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
