/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:09:16 by slott             #+#    #+#             */
/*   Updated: 2021/11/19 17:17:04 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *save;
	char *tmp;
	char *tab;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	tmp = malloc (BUFFER_SIZE * sizeof(char) + 1);
	if (!tmp)
		return (NULL);
	if (!save)
		save = malloc(BUFFER_SIZE * sizeof(char) + 1);
	tab = get_line(fd, tmp, save);
	free(tmp);
	return (tab);
}

char *get_line(int fd, char *tmp, char *save)
{
	int lu;

	if (check_save(save))
		return (ft_extract(save));
	lu = read_file(fd, tmp, save);
	if ((lu == 0 || !lu) && save[0] == 0)
	{
		free(save);
		return (NULL);
	}
	if (check_save(save))
		return (ft_extract(save));
	if (save[0] == 0)
		return (NULL);
	return (save);
}

int	read_file(int fd, char *tmp, char *save)
{
	int	lu;

	lu = 1;
	while (check_save(save) == 0 && lu > 0)
	{
		lu = read(fd, tmp, BUFFER_SIZE);
		if (lu == -1)
			return (lu);
		save = save + tmp;
	}
}

char	*ft_extract(char *save)
{
	int		c;
	char	*li;

	c = 0;
	while (save[i] != '\n' && save[c])
	{
		li[c] = save[c];
		c++;
	}
	ft_trim(save);
	return (li);
}
