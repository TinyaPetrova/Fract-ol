/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upetrova <upetrova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:29:49 by upetrova          #+#    #+#             */
/*   Updated: 2025/08/06 15:52:50 by upetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(t_complex_params p)
{
	double	zx;
	double	zy;
	double	temp;
	int		iter;

	iter = 0;
	zx = 0;
	zy = 0;
	while (zx * zx + zy * zy <= 4 && iter < p.max_iter)
	{
		temp = zx * zx - zy * zy + p.x;
		zy = 2 * ft_fabs(zx * p.cre) * ft_fabs(zy * p.cim) + p.y;
		zx = temp;
		iter++;
	}
	return (iter);
}
