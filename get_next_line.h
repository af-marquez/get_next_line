/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:42 by amarquez          #+#    #+#             */
/*   Updated: 2021/04/30 12:18:43 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>


#ifndef		BUFFER_SIZE
# define	BUFFER_SIZE 1

#endif

int	get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
void	*ft_bzero(void *s, size_t n);
char	*ft_dup(char *s);
char	*first_trt(char *s);
char	*second_trt(char *s);

#endif
