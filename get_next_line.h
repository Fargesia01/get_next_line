/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:07:09 by slott             #+#    #+#             */
/*   Updated: 2021/11/16 15:46:13 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdio.h"
# include "unistd.h"
# include "fcntl.h"
# include "stdlib.h"

char	*ft_strjoin(char *save, char *tab);
int		check_save(char *save);
char	*ft_trim(char *save);

#endif
