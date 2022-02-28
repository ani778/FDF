/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:37:23 by anhovhan          #+#    #+#             */
/*   Updated: 2022/02/23 14:45:45 by anhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 10
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>

int		ft_atoi_base(char *str, char *base);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
int		get_next_line(int fd, char **line);
int		ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *string, char *buff);
char	*new_line(char *string);
char	*ft_strnew_gnl(char *string);
int		is_next_line(char *string);
char	*ft_remline_gnl(char *rem_line);
int		ft_str_endline_gnl(char *str);
char	*ft_strjoin_gnl(char *rem_line, char *buffer);
char	*ft_clearrem_gnl(char *rem_line);
char	**ft_split(char const *s, char c);
void	ft_str_tolower(char *str);
int		is_color(char *str);
int		is_space(char c);
int		get_value(char c, char *base);
int		check_sign(char *str, int i, int *sign);
#endif
