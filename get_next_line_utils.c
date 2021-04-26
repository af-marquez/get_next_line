/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:28 by amarquez          #+#    #+#             */
/*   Updated: 2021/04/26 15:43:12 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *str)
{
	int	len;

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
