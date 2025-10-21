/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:43:43 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/07 15:13:17 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_str_float(char *s)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (dot)
				return (0);
			dot = 1;
		}
		else if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_float(char *s)
{
	int		i;
	int		len;
	int		sign;
	double	val;

	if (!is_str_float(s))
		return (0);
	i = 0;
	len = 0;
	sign = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		sign = 1;
		i++;
	}
	while (s[i])
	{
		if (s[i] != '.')
			len++;
		i++;
	}
	val = ft_atof(s);
	if (val < -2.0 || val > 2.0)
		return (0);
	return (1);
}

int	validate_input_b(int argc, char **argv)
{
	if (!argv[1])
		return (0);
	if (ft_strcmp(argv[1], "mandelbrot") == 0
		|| ft_strcmp(argv[1], "burning_ship") == 0)
	{
		if (argc != 2)
			return (0);
	}
	else if (ft_strcmp(argv[1], "julia") == 0
		|| ft_strcmp(argv[1], "spider") == 0)
	{
		if (argc == 2)
			return (1);
		if (argc != 4)
			return (0);
		if (!is_valid_float(argv[2])
			|| !is_valid_float(argv[3]))
			return (0);
	}
	else
		return (0);
	return (1);
}
