/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:40:38 by anhovhan          #+#    #+#             */
/*   Updated: 2022/02/25 11:20:22 by anhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_check(char *f_name, t_fdf *data)
{
	int		w;
	int		w_new;
	char	*line;
	int		fd;

	fd = open(f_name, O_RDONLY);
	get_next_line(fd, &line);
	w = ft_word_count(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
	{
		w_new = ft_word_count(line, ' ');
		if (w > w_new)
		{
			write(1, "ERROR!\n", 7);
			exit(0);
		}
		free(line);
	}
	data->width = w;
	free(line);
	close(fd);
}

int	get_heidht(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_word_count(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, int *color_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		color_line[i] = ft_atoi_base(nums[i], "0123456789abcdef");
		i++;
	}
	i = 0;
	while (nums[i])
		free(nums[i++]);
	free(nums);
}

void	read_file(char *file_name, t_fdf *info)
{
	int		i;
	int		fd;
	char	*line;

	info->height = get_heidht(file_name);
	info->width = get_width(file_name);
	info->z_color = malloc(sizeof(int *) * info->height);
	i = 0;
	while (i < info->height)
		info->z_color[i++] = malloc(sizeof(int *) * (info->width));
	info->z_matrix = malloc(sizeof(int *) * (info->height));
	i = 0;
	while (i < info->height)
		info->z_matrix[i++] = malloc(sizeof(int *) * (info->width));
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(info->z_matrix[i], info->z_color[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	info->z_matrix[i] = 0;
}
