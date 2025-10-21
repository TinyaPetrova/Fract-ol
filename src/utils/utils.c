/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:03:28 by upetrova          #+#    #+#             */
/*   Updated: 2025/07/26 21:12:30 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double val, t_range from, t_range to)
{
	double	range1;
	double	range2;
	double	normalized;

	range1 = from.max - from.min;
	range2 = to.max - to.min;
	normalized = (val - from.min) / range1;
	return (normalized * range2 + to.min);
}

static double	parse_integer_part(char *str, int *i)
{
	double	res;

	res = 0.0;
	while (str[*i] && str[*i] != '.')
	{
		res = res * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (res);
}

static double	parse_fraction_part(char *str, int *i)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 0.1;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i])
		{
			fraction += (str[*i] - '0') * divisor;
			divisor *= 0.1;
			(*i)++;
		}
	}
	return (fraction);
}

static int	get_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (sign);
}

double	ft_atof(char *str)
{
	double	res;
	int		sign;
	int		i;

	i = 0;
	sign = get_sign(str, &i);
	res = parse_integer_part(str, &i);
	res += parse_fraction_part(str, &i);
	return (res * sign);
}
