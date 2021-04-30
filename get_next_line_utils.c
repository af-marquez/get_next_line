/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:28 by amarquez          #+#    #+#             */
/*   Updated: 2021/04/30 01:13:03 by amarquez         ###   ########.fr       */
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
char	*ft_dup(char *s)
{
	char *new;
	int	index;
	
	new = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (0);
	index = 0;
	while (s[index])
	{
		new[index] = s[index];
		index++;
	}
	new[index] = 0;
	return (new);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char			*newstr;
	unsigned int	jindex;
	unsigned int 	index;

	index = 0;
	jindex = 0;
	
	if (!s1)
		return (ft_dup(s2));
	
	if (!s2)
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
	char			*str1;

	str1 = (char *)str;
	index = 0;

	while (*(str1 +index))
	{
		if (*(str1 + index) == (char)c)
			return (str1 + index);
		index++;
	}
	return (0);
}

void	*ft_bzero(void	*s, size_t n)
{
	size_t	index;
	unsigned char *s1;

	index = 0;
	s1 = (unsigned char *)s;
	while (index < n)
	{
		s1[index] = 0;
		index++;
	}
	return (s1);
}
