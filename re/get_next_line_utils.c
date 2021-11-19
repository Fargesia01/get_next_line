/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:11:48 by slott             #+#    #+#             */
/*   Updated: 2021/11/19 17:17:06 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	check_save(char *save)
{
	int	c;

	c = 0;
	while (save[c])
	{
		if (save[c] == '\n')
			return (1);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

char	*ft_strdup(char *str)
{
	int	c;
	int	size;
	char	*clone;
	
	size = ft_strlen(str);
	clone = malloc(size * sizeof(char) + 1);
	if (!clone)
		return (NULL);
	c = -1;
	while (c < size)
	{
		clone[c] = str[c];
		c++;
	}
	return (clone);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char *str;
	int	c;
	int	c2;

	if (!str1 || !str2)
		return (NULL);
	str = malloc((ft_strlen(str1) + ft_strlen(str2)) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	c = -1;
	while (str1[c])
	{
		str[c] = str1[c];
		c++;
	}
	c2 = -1;
	while(str2[c2])
	{
		str[c + c2] = str2[c2];
		c2++;
	}
	str[c + c2] = 0;
	return (str);
}
