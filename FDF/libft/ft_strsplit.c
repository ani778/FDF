/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:09:50 by anhovhan          #+#    #+#             */
/*   Updated: 2022/02/23 13:20:39 by anhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	word_len(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

void	*free_mall(char **splitted, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (NULL);
}

char	**word(char const *s, int words, char c, char **mall)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (++i < words)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		mall[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!mall[i])
			return (free_mall(mall, i));
		j = 0;
		while (j < len)
			mall[i][j++] = *s++;
		mall[i][j] = '\0';
	}
	mall[i] = NULL;
	return (mall);
}

char	**ft_split(char const *s, char c)
{
	char	**mall;
	int		words;

	if (!s)
		return (NULL);
	words = ft_word_count(s, c);
	mall = (char **)malloc(sizeof(char *) * (words + 1));
	if (!mall)
		return (NULL);
	mall = word(s, words, c, mall);
	return (mall);
}
