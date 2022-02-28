/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:39:12 by anhovhan          #+#    #+#             */
/*   Updated: 2022/02/25 11:16:47 by anhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_pressed(int key_code, t_fdf *info)
{
	int	i;

	if (key_code == K_ESC)
	{
		i = 0;
		while (i < info->height)
		{
			free(info->z_matrix[i]);
			free(info->z_color[i]);
			i++;
		}
		free(info->z_matrix);
		free(info->z_color);
		exit(0);
	}
	return (0);
}

int	key_hook(long key)
{
	if (key)
		exit(0);
	return (0);
}
