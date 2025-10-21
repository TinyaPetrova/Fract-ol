/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_preview_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:10:32 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 16:19:16 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fill_preview_block(t_img *img, int x, int y, int color)
{
	int	dy;
	int	dx;

	dy = 0;
	while (dy < 4 && y + dy < HEIGHT)
	{
		dx = 0;
		while (dx < 4 && x + dx < WIDTH)
		{
			put_pixel(img, x + dx, y + dy, color);
			dx++;
		}
		dy++;
	}
}

static void	calc_preview_coords(t_fractal *f, t_complex_params *p, int x, int y)
{
	t_range	from;
	t_range	to;

	from.min = 0;
	from.max = WIDTH;
	to.min = -2.0 / f->zoom + f->offset_x;
	to.max = 2.0 / f->zoom + f->offset_x;
	p->x = map(x, from, to);
	from.min = 0;
	from.max = HEIGHT;
	to.min = -2.0 / f->zoom + f->offset_y;
	to.max = 2.0 / f->zoom + f->offset_y;
	p->y = map(y, from, to);
}

static int	calc_preview_iter(t_fractal *f, t_complex_params *p)
{
	if (f->type == MANDELBROT)
		return (mandelbrot(p->x, p->y, p->max_iter));
	else if (f->type == JULIA)
	{
		p->cre = f->julia_re;
		p->cim = f->julia_im;
		return (julia(*p));
	}
	else if (f->type == SPIDER)
	{
		p->cre = f->spider_re;
		p->cim = f->spider_im;
		return (spider(*p));
	}
	else if (f->type == BURNING_SHIP)
	{
		p->cre = f->ship_cre;
		p->cim = f->ship_cim;
		return (burning_ship(*p));
	}
	return (0);
}

void	draw_fractal_preview(t_fractal *f)
{
	t_complex_params	p;
	int					color;
	int					x;
	int					y;

	p.max_iter = f->max_iter / 2;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			calc_preview_coords(f, &p, x, y);
			color = colorize_b(calc_preview_iter(f, &p), f->max_iter / 2,
					f->palette);
			fill_preview_block(&f->img, x, y, color);
			x += 4;
		}
		y += 4;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
