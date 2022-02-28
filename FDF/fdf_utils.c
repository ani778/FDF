/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:42:14 by anhovhan          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:20 by anhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clear(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_L)
		{
			my_mlx_pixel_put(&data->image, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

int	ft_frame(t_fdf *info)
{
	ft_clear(info);
	draw(info);
	mlx_put_image_to_window(info->mlx_ptr,
		info->win_ptr, info->image.img, 0, 0);
	mlx_do_sync(info->mlx_ptr);
	return (1);
}

void	ft_initizilation(t_fdf *info)
{
	info->coefficient = 20;
	info->move_x = WIN_L / 2;
	info->move_y = WIN_H / 2;
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bbp / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_hook_loop(t_fdf *data)
{
	mlx_hook(data->win_ptr, 2, 0, key_pressed, data);
	mlx_hook(data->win_ptr, 17, 0, key_hook, data);
	mlx_loop_hook(data->mlx_ptr, ft_frame, data);
	mlx_loop(data->mlx_ptr);
}
