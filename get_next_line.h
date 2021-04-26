/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:42 by amarquez          #+#    #+#             */
/*   Updated: 2021/04/26 13:28:23 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

#ifndef		BUFFER_SIZE
# define	BUFFER_SIZE 1024

#endif

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int	get_next_line(int fd, char **line);
int	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);

#endif
