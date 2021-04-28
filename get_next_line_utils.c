/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:28 by amarquez          #+#    #+#             */
/*   Updated: 2021/04/28 15:51:42 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char			*newstr;
	unsigned int	jindex;
	unsigned int 	index;

	index = 0;
	jindex = 0;
	if (!s1 || !s2)
		return (0);
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (0);
	while (s1[index])
	{
		newstr[index] = s1[index];
		index++;
	}
	while (s1[jindex])
	{
		newstr[index] = s2[jindex];
		index++;
		jindex++;
	}
	newstr[index] = '\0';
	return (newstr);
}

char	*ft_strchr(char *str, int c)
{
	int	index;

	index = 0;
	while (str[index] != (char)c)
	{
		if (!str[index++])
			return (0);
	}
	return ((char *)&str[index]);
}
