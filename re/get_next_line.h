/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:10:01 by slott             #+#    #+#             */
/*   Updated: 2021/11/19 17:17:08 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
#include "stdlib.h"

char	*get_next_line(int fd);
int		check_save(char *save);
char	*get_line(int fd, char *tmp, char *save);
int		read_file(int fd, char *tmp, char *save);
char	*ft_extract(char *save);

#endif
