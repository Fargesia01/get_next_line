/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:05:53 by slott             #+#    #+#             */
/*   Updated: 2021/11/22 17:39:42 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*tab;
	int			trigger;
	static char	*save[257];

	trigger = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	tab = malloc(sizeof(char));
	tab[0] = 0;
	if (!save[fd])
	{
		save[fd] = malloc(BUFFER_SIZE * sizeof(char) + 1);
		save[fd][BUFFER_SIZE] = 0;
	}
	else
	{
		if (check_save(save[fd]))
			trigger = 1;
		tab = ft_strjoin(save[fd], tab);
		save[fd] = ft_trim(save[fd]);
	}
	while (!check_save(save[fd]) && trigger == 0)
	{
		if (read(fd, save[fd], BUFFER_SIZE) == 0)
			trigger = 2;
		tab = ft_strjoin(save[fd], tab);
	}
	if (trigger == 0)
		save[fd] = ft_trim(save[fd]);
	if  (save[fd] && save[fd][0] == 0 && trigger == 2)
	{
		free_ptr(save[fd]);
		free_ptr(tab);
		return (NULL);
	}
	return (tab);
}

void	free_ptr(char *ptr)
{
	free(ptr);
	ptr = NULL;
}

/*int	main()
{
	int fd;
	char *tab;

	fd = open("test", O_RDWR | O_APPEND);
	tab = get_next_line(fd);
	printf("%s", tab);
	tab = get_next_line(fd);
	printf("%s", tab);
	tab = get_next_line(fd);
	printf("%s", tab);
	close(fd);
}*/
