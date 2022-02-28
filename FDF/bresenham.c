/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:58:38 by anhovhan          #+#    #+#             */
/*   Updated: 2022/02/23 13:41:44 by anhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_coord xyz, t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	max;

	pointed(&xyz, data);
	data->color = data->z_color[(int)xyz.y1][(int)xyz.x1];
	ft_zoom(&xyz, data);
	isometric(&xyz.x, &xyz.y, xyz.z);
	isometric(&xyz.x1, &xyz.y1, xyz.z1);
	ft_shift(&xyz, data);
	x_step = xyz.x1 - xyz.x;
	y_step = xyz.y1 - xyz.y;
	max = ft_max(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	while (((int)(xyz.x1 - xyz.x) || (int)(xyz.y1 - xyz.y)))
	{
		if ((xyz.y < WIN_H) && (xyz.x < WIN_L))
		{
			if (xyz.x >= 0 && xyz.y >= 0)
				my_mlx_pixel_put(&data->image, xyz.x, xyz.y, data->color);
		}
		xyz.x += x_step;
		xyz.y += y_step;
	}
}

void	draw(t_fdf *data)
{
	t_coord	xyz;

	xyz.y = 0;
	while ((xyz.y < data->height))
	{
		xyz.x = 0;
		while (xyz.x < data->width)
		{
			if (xyz.x < data->width - 1)
			{
				xyz.x1 = xyz.x + 1;
				xyz.y1 = xyz.y;
				bresenham(xyz, data);
			}
			if (xyz.y < data->height - 1)
			{
				xyz.x1 = xyz.x;
				xyz.y1 = xyz.y + 1;
				bresenham(xyz, data);
			}
			xyz.x++;
		}
		xyz.y++;
	}
}

void	pointed(t_coord *xyz, t_fdf *data)
{
	(*xyz).z = data->z_matrix[(int)(*xyz).y][(int)(*xyz).x];
	(*xyz).z1 = data->z_matrix[(int)(*xyz).y1][(int)(*xyz).x1];
}

void	ft_zoom(t_coord *xyz, t_fdf *data)
{
	(*xyz).x *= data->coefficient;
	(*xyz).x1 *= data->coefficient;
	(*xyz).y *= data->coefficient;
	(*xyz).y1 *= data->coefficient;
}

void	ft_shift(t_coord *xyz, t_fdf *info)
{
	(*xyz).x += info->move_x;
	(*xyz).x1 += info->move_x;
	(*xyz).y += info->move_y;
	(*xyz).y1 += info->move_y;
}
