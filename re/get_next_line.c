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
	if (!save)
		save = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!save || !tmp)
		return (NULL);
	tab = get_line(fd, tmp, save);
	free(tmp);
	return (tab);
}

char *get_line(int fd, char *tmp, char *save)
{
	int		lu;
	char	*tmp_free;

	if (check_save(save))
		return (ft_extract(save));
	lu = read_file(fd, tmp, save);
	if ((lu == 0 || lu == -1) && !save)
	{
		free(save);
		return (NULL);
	}
	if (check_save(save))
		return (ft_extract(save));
	if (!check_save(save) && save)
	{
		tmp_free = ft_strdup(save);
		free(save);
		save = NULL;
		return (tmp_free);
	}
	return (NULL);
}

int	read_file(int fd, char *tmp, char *save)
{
	int	lu;

	lu = 1;
	while (check_save(save) == 0 && lu)
	{
		lu = read(fd, tmp, BUFFER_SIZE);
		if (lu == -1)
			return (lu);
		tmp[lu] = 0;
		save = ft_strjoin(save, tmp);
	}
	return (lu);
}

char	*ft_extract(char *save)
{
	int		c;
	char	*li;

	c = 0;
	while (save[c] != '\n' && save[c])
		c++;
	li = malloc(c * sizeof(char) + 1);
	c = 0;
	while (save[c] && save[c] != '\n')
	{
		li[c] = save[c];
		c++;
	}
	return (li);
}

/*int main()
{
	
}*/
