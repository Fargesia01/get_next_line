/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:08:45 by slott             #+#    #+#             */
/*   Updated: 2021/11/16 17:27:22 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strjoin(char *save, char *tab)
{
	char	*join;
	int		c;
	int		c2;

	c = 0;
	c2 = 0;
	while (tab[c])
		c++;
	while (save[c2] && save[c2] != '\n')
		c2++;
	join = malloc((c + c2) * sizeof(char) + 1);
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
	join[c + c2] = 0;
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
	c++;
	while (save[c + c2])
		c2++;
	tab = malloc(c2 * sizeof(char) + 1);
	c = 0;
	c2 = 0;
	while (save[c] && save[c] != '\n')
		c++;
	c++;
	while (save[c])
	{
		tab[c2] = save[c];
		c2++;
		c++;
	}
	tab[c] = 0;
	return (tab);
}
