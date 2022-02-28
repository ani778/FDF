/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:11:19 by anhovhan          #+#    #+#             */
/*   Updated: 2022/02/23 15:01:59 by anhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_base(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 127 || is_space(str[i])
			|| str[i] == '-' || str[i] == '+')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_color(char *str)
{
	if (!is_color(str))
	{
		if (ft_atoi(str) > 0)
			return (0x006600FF);
		else if (ft_atoi(str) < 0)
			return (0x00FF33FF);
		else
			return (0x00FF99FF);
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		b;
	int		sign;
	long	res;

	ft_str_tolower(str);
	if (ft_is_color(str))
		return (ft_is_color(str));
	i = 0;
	sign = 1;
	res = 0;
	if (!check_base(base))
		return (0);
	b = ft_strlen(base);
	i = check_sign(str, i, &sign);
	while (str[i] != 'x')
		i++;
	i++;
	while (get_value(str[i], base) >= 0)
	{
		res = res * b + get_value(str[i], base);
		i++;
	}
	return (res * sign);
}
