#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
	{
		len++;
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
	new[index] = '\0';
	return (new);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char			*newstr;
	int		j;
	int 	i;

	i = 0;
	j = 0;
	
	if (!s1)
		return (ft_dup(s2));
	newstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (0);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s1[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strchr(char *s, int c)
{
	char			*str;

	str = (char *)str;
	if (!str)
		return (0);
	while (*str != c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (str);
}

// .... this part deals with what is after the \n	
char	*second_trt(char *s)
{
	int		i;
	int		j;
	char	*line_keep;

	if (!s)
		return (0);
	i = 0;
	while(s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return(0);
	}
	line_keep = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!line_keep)
		return (0);
	i++;
	j = 0;
	while (s[i])
	{
		line_keep[j] = s[i];
		i++;
		j++;
	}
	line_keep[i] ='\0';
	return (line_keep);
}

// .... this part deals with what is before the \n	
char	*first_trt(char *s)
{
	int		i;
	char	*new_line;

	if (!s)
		return (0);
	i = 0;
	while (s[i] !='\n' && s[i])
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (0);
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		new_line[i] = s[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

