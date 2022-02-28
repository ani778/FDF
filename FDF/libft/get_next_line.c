/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:23:07 by anhovhan          #+#    #+#             */
/*   Updated: 2022/02/23 15:42:41 by anhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	int			readed;
	static char	*rem_line;

	buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buffer || fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	readed = read(fd, buffer, BUFFER_SIZE);
	while (readed > 0)
	{
		buffer[readed] = '\0';
		rem_line = ft_strjoin_gnl(rem_line, buffer);
		if (ft_str_endline_gnl(rem_line))
			break ;
		readed = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (readed < 0)
		return (-1);
	*line = ft_remline_gnl(rem_line);
	rem_line = ft_clearrem_gnl(rem_line);
	if (readed == 0 && !rem_line)
		return (0);
	return (1);
}
