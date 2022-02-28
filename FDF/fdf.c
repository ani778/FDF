/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:57:12 by anhovhan          #+#    #+#             */
/*   Updated: 2022/02/25 11:16:17 by anhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	*data;

	fd = open(argv[1], O_RDONLY);
	if (argc == 1 || argc > 2 || fd < 0)
	{
		write(1, "ERROR!\n", 7);
		exit(0);
	}
	close(fd);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	map_check(argv[1], data);
	read_file(argv[1], data);
	ft_initizilation(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_L, WIN_H, "FDF");
	data->image.img = mlx_new_image(data->mlx_ptr, WIN_L, WIN_H);
	data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bbp,
			&data->image.line_len, &data->image.endian);
	my_mlx_hook_loop(data);
	free(data);
}
