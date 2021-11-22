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
	static char *save[257];
	char *tmp;
	char *tab;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 257)
		return (NULL);
	tmp = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!tmp)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_strdup("");
	tab = get_line(fd, tmp, save[fd]);
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
		free_ptr(save);
		return (NULL);
	}
	if (check_save(save))
		return (ft_extract(save));
	if (!check_save(save) && save)
	{
		tmp_free = ft_strdup(save);
		free_ptr(save);
		return (tmp_free);
	}
	return (NULL);
}

int	read_file(int fd, char *tmp, char *save)
{
	int	lu;
	char	*tmp_free;

	lu = 1;
	while (!check_save(save) == 0 && lu)
	{
		lu = read(fd, tmp, BUFFER_SIZE);
		if (lu == -1)
			return (lu);
		tmp[lu] = 0;
		tmp_free = save;
		save = ft_strjoin(tmp_free, tmp);
		free_ptr(tmp_free);
	}
	return (lu);
}

char	*ft_extract(char *save)
{
	int		c;
	char	*li;
	char	*tmp_free;

	c = 0;
	while (save[c] && save[c] != '\n')
		c++;
	tmp_free = save;
	li = ft_substr(tmp_free, 0, c + 1);
	save = ft_strdup(&save[c + 1]);
	free_ptr(tmp_free);
	return (li);
}

void	free_ptr(char *ptr)
{
	free(ptr);
	ptr = NULL;
}

int main()
{
	int	fd;
	char	*tab;

	fd = open("test", O_RDWR | O_APPEND);
	//tab = get_next_line(fd);
	//printf("%s\n", tab);
	//tab = get_next_line(fd);
	//printf("%s\n", tab);
	tab = get_next_line(fd);
	printf("final :%s\n", tab);
	close(fd);
}
