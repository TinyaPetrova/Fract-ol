/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:28:29 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 16:38:21 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <time.h>
# include <string.h>
# include "minilibx-linux/mlx.h"

# define WIDTH 1500
# define HEIGHT 1500
# define MAX_ITER 100

# define MANDELBROT 1
# define JULIA 2

# define SPIDER 3
# define BURNING_SHIP 4

# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define PLUS_KEY 61
# define EQUAL_KEY 61
# define MINUS_KEY 45
# define UNDERSCORE_KEY 95
# define C_KEY 99
# define L_KEY 108
# define MOVE_STEP 0.1

# define ESC_KEY 65307
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

# define CLOSE_EVENT 17
# define NO_MASK 0

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}				t_img;

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		type;
	int		max_iter;
	double	zoom;
	double	offset_x;
	double	offset_y;
	double	julia_re;
	double	julia_im;
	double	spider_re;
	double	spider_im;
	double	ship_cre;
	double	ship_cim;
	int		needs_redraw;
	int		palette;
	int		mouse_lock;
}				t_fractal;

typedef struct s_complex_params
{
	double	x;
	double	y;
	double	cre;
	double	cim;
	int		max_iter;
}				t_complex_params;

typedef struct s_pixel
{
	double	zx;
	double	zy;
	double	temp;
	double	cr;
	double	ci;
}				t_pixel;

typedef struct s_draw_params
{
	int		x;
	int		y;
	int		iter;
	int		step;
	double	step_x;
	double	step_y;
	double	min_x;
	double	min_y;
}				t_draw_params;

typedef struct s_range
{
	double	min;
	double	max;
}				t_range;

void	draw_fractal_b(t_fractal *f);
void	draw_fractal_m(t_fractal *f);
void	put_pixel(t_img *img, int x, int y, int color);
int		mandelbrot(double x, double y, int max_iter);
int		julia(t_complex_params p);
int		colorize_b(int iter, int max_iter, int palette);
int		colorize_m(int iter, int max_iter);
void	print_usage_b(void);
void	print_usage_m(void);
double	ft_atof(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
double	ft_fabs(double x);
int		validate_input_b(int argc, char **argv);
int		validate_input_m(int argc, char **argv);
void	init_fractal_b(t_fractal *f, char **argv, int argc);
void	init_fractal_m(t_fractal *f, char **argv, int argc);
int		close_exit_b(t_fractal *fractal);
int		close_exit_m(t_fractal *fractal);
int		handle_mouse_b(int button, int x, int y, t_fractal *fractal);
int		handle_mouse_m(int button, int x, int y, t_fractal *fractal);
int		handle_key_b(int key, t_fractal *fractal);
int		handle_key_m(int key, t_fractal *fractal);
int		init_mlx(t_fractal *fractal);
void	setup_hooks_b(t_fractal *fractal);
void	setup_hooks_m(t_fractal *fractal);
void	draw_fractal_preview(t_fractal *f);
int		spider(t_complex_params p);
int		burning_ship(t_complex_params p);
double	map(double val, t_range from, t_range to);
void	init_fractal_base(t_fractal *f);
void	init_julia_fractal(t_fractal *f, char **argv, int argc);
void	init_spider_fractal(t_fractal *f, char **argv, int argc);
int		handle_motion(int x, int y, void *param);
int		idle_hook(t_fractal *fractal);
double	get_mouse_real(int x, t_fractal *fractal);
double	get_mouse_imag(int y, t_fractal *fractal);
void	zoom_in(t_fractal *f, double mouse_re, double mouse_im, double factor);
void	zoom_out(t_fractal *f, double mouse_re, double mouse_im, double factor);
void	adjust_iterations_for_zoom(t_fractal *fractal);
int		handle_movement_keys(int key, t_fractal *fractal);
int		handle_iteration_keys(int key, t_fractal *fractal);
int		handle_special_keys(int key, t_fractal *fractal);
void	handle_fractal_motion(int x, int y, t_fractal *fractal);
void	handle_julia_motion(int x, int y, t_fractal *fractal);
void	handle_spider_motion(int x, int y, t_fractal *fractal);
void	handle_mandelbrot_motion(int x, int y, t_fractal *fractal);
void	handle_ship_motion(int x, int y, t_fractal *fractal);

#endif
