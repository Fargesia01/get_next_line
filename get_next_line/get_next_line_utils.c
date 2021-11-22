/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:08:45 by slott             #+#    #+#             */
/*   Updated: 2021/11/22 17:39:45 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strjoin(char *save, char *tab)
{
	char	*join;
	int		c;
	int		c2;
	
	join = malloc((ft_strlen(save) + ft_strlen(tab)) * sizeof(char) + 1);
	if (!join)
		return (NULL);
	c = 0;
	c2 = 0;
	while (tab[c])
	{
		join[c] = tab[c];
		c++;
	}	
	while (save[c2] && save[c2] != '\n')
	{
		join[c + c2] = save[c2];
		c2++;
	}
	if (save[c2] == '\n')
	{
		join[c + c2] = save[c2];
		c2++;
	}
	join[c + c2] = 0;
	free_ptr(tab);
	return (join);
}

int	check_save(char *save)
{
	int	c;
	c = 0;
	while (save[c])
	{
		if (save[c] == '\n')
		{
			return (1);
		}	
		c++;
	}
	return (0);
}

char	*ft_trim(char *save)
{
	int		c;
	int 	c2;
	char	*tab;

	c = 0;
	c2 = 0;
	while (save[c] && save[c] != '\n')
		c++;
	if (save[c] == '\n')
		c++;
	while (save[c + c2])
		c2++;
	tab = malloc(BUFFER_SIZE * sizeof(char) + 1);
	c2 = 0;
	while (save[c])
	{
		tab[c2] = save[c];
		c2++;
		c++;
	}
	tab[c2] = 0;
	free_ptr(save);
	return (tab);
}

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}
