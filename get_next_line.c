/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:05:53 by slott             #+#    #+#             */
/*   Updated: 2021/11/16 17:27:19 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

#define BUF_SIZE 1

int		check_tmp(char *tmp);
char	*cpy_tmp(char *tmp, char *tab);
char	*save_tmp(char *tmp);

char	*get_next_line(int fd)
{
	char		*tab;
	static char	*save;

	tab = "\0";
	if (!save)
		save = malloc(BUF_SIZE * sizeof(char) + 1);
	else
	{
		tab = ft_strjoin(save, tab);
		save = ft_trim(save);
	}
	while (!check_save(save))
	{
		read(fd, save, BUF_SIZE);
		tab = ft_strjoin(save, tab);
	}
	save = ft_trim(save);
	return (tab);
}

int	main()
{
	int fd;
	char *tab;

	fd = open("test", O_RDWR | O_APPEND);
	//tab = get_next_line(fd);
	//tab = get_next_line(fd);
	tab = get_next_line(fd);
	tab = get_next_line(fd);
	printf("%s\n", tab);
	close(fd);
}
