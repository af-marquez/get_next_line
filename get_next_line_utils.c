/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:28 by amarquez          #+#    #+#             */
/*   Updated: 2021/04/20 19:02:48 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		index;

	index = 0;
	new = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new)
		return (0);
	if (!s1)
		return (0);
	while (s1[index] != '\0')
	{
		new[index] =s1[index];
		index ++;
	}
	new[index] = '\0';
	return (new);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*newstr;
	unsigned int	jindex;
	unsigend int 	index;

	index = 0;
	jindex = 0;
	if (!s1 || !s2)
		return (0);
	newstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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

char	*ft_strchr(const char *str, int c)
{
	unsigned int	index;
	char			*str1;

	str1 = (char *)str;
	index = 0;

	while (*(str1 +index))
	{
		if (*(str1 + index) == (char)c)
			return (str1 + index)
		index++;
	}
	return (0);
}
