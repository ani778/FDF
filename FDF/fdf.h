/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:35:48 by anhovhan          #+#    #+#             */
/*   Updated: 2022/02/25 11:23:44 by anhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# define K_ESC 53
# define WIN_H 1080
# define WIN_L 1920

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bbp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fdf
{
	int		coefficient;
	int		width;
	int		height;
	int		**z_matrix;
	int		**z_color;
	int		zoom;
	int		color;
	void	*mlx_ptr;
	void	*win_ptr;
	int		move_x;
	int		move_y;
	t_img	image;
}	t_fdf;

typedef struct s_coord
{
	float	x;
	float	x1;
	float	y;
	float	y1;
	int		z;
	int		z1;
}	t_coord;

int		get_next_line(int fd, char **line);
int		ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *string, char *buff);
char	*ft_strnew_gnl(char *string);
int		is_next_line(char *string);
char	*new_line(char *string);
char	*ft_strnew_gnl(char *string);
int		ft_word_count(char const *s, char c);
int		ft_atoi_base(char *str, char *base);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *s);
float	ft_max(float x, float y);
void	read_file(char *file_name, t_fdf *data);
void	bresenham(t_coord xyz, t_fdf *data);
void	ft_zoom(t_coord *xyz, t_fdf *data);
float	ft_max(float x, float y);
void	ft_shift(t_coord *xyz, t_fdf *info);
void	draw(t_fdf *data);
void	ft_choose_color(int *z, t_fdf *info);
int		key_pressed(int key_code, t_fdf *info);
int		key_hook(long key);
void	ft_clear(t_fdf *data);
int		ft_frame(t_fdf *info);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	isometric(float *x, float *y, int z);
void	ft_initizilation(t_fdf *info);
void	pointed(t_coord *xyz, t_fdf *data);
void	my_mlx_hook_loop(t_fdf *data);
void	map_check(char *f_name, t_fdf *data);
#endif
