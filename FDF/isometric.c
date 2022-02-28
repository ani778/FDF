/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:01:50 by anhovhan          #+#    #+#             */
/*   Updated: 2022/02/23 13:59:25 by anhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	deg_to_rad(double deg)
{
	return (deg * M_PI / 190);
}

void	isometric(float *x, float *y, int z)
{
	double	rad;

	rad = deg_to_rad(60);
	*x = (*x - *y) * cos(rad);
	*y = (*x + *y) * sin(rad) - z;
}

float	ft_max(float x, float y)
{
	if (x > y)
		return (x);
	else
		return (y);
}
