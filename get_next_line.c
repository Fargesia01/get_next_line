/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:05:53 by slott             #+#    #+#             */
/*   Updated: 2021/11/15 16:26:15 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int		check_tmp(char *tmp);
char	*cpy_tmp(char *tmp, char *tab);

char	*get_next_line(int fd)
{
	char		*tab;
	char		*tmp;
	int			fin;
	static int	ret;

	fin = 0;
	tmp = malloc(4 * sizeof(char) + 1);
	tab = "\0";
	while (!check_tmp(tmp))
	{
		fin += read(fd, tmp, 4);
		tab = cpy_tmp(tmp, tab);
	}
	ret = fin - check_tmp(tmp) + 1;
	printf("%d\n", ret);
	tab[fin] = 0;
	return (tab);
}

char	*cpy_tmp(char *tmp, char *tab)
{
	char	*join;
	int		c;
	int		c2;

	c = 0;
	c2 = 0;
	while (tab[c])
		c++;
	while (tmp[c2] && tmp[c2] != '\n')
		c2++;
	join = malloc((c + c2) * sizeof(char));
	if (!join)
		return (NULL);
	c = 0;
	c2 = 0;
	while (tab[c])
	{
		join[c] = tab[c];
		c++;
	}
	while (tmp[c2] && tmp[c2] != '\n')
	{
		join[c + c2] = tmp[c2];
		c2++;
	}
	return (join);
}

int	check_tmp(char *tmp)
{
	int	c;
	int	c2;

	c2 = 0;
	c = 0;
	while (tmp[c])
	{
		if (tmp[c] == '\n')
		{
			c++;
			while (tmp[c])
			{
				c2++;
				c++;
			}
			return (c2);
		}	
		c++;
	}
	return (0);
}

int	main()
{
	int fd;
	char *tab;

	//printf("%s\n", cpy_tmp("oooo\nkkkkkkkk\nllllllll\n\n", "\0"));

	fd = open("test", O_RDWR | O_APPEND);
	//tab = get_next_line(fd);
	tab = get_next_line(fd);
	tab = get_next_line(fd);
	printf("%s", tab);
	close(fd);
}
