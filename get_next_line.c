/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:13 by amarquez          #+#    #+#             */
/*   Updated: 2021/04/28 15:51:21 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	//guarda posição onde é lido
	static char	*keep[OPEN_MAX];
	//mantem linha lida e vai ser junta com a linha salva
	char		buf[BUFFER_SIZE + 1];
	//conta nr linhas lidas
	int 		n_read;
	char 		*new_line;
	int 		index;
	char		*line_keep;
	int			j;
	int		len;

	if (!line || (read(fd, 0 ,0) == -1) || BUFFER_SIZE < 1)
		return (-1);
	// n_read = -1 erro , zero EOF ou 1 linha lida
	// determinar se é linha ou nao
	
	n_read = 1;
	while (ft_strchr(keep[fd], '\n') == 0 && n_read != 0)
	{
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read == -1)
		{
			free(buf);
			return(-1);
		}
		buf[n_read] = 0;
		keep[fd] = ft_strjoin(keep[fd],buf);
	}
	free (buf);
	
	// ....
	len = ft_strlen(ft_strchr(buf, '\n'));	
	new_line =malloc(sizeof(char) * (len + 1));
	if (!new_line)
		return (0);
	index = 0;
	while (buf[index] != '\n' && buf[index])
	{
		new_line[index] = buf[index];
		index++;
	}
	new_line[index] = '\0';
	*line = new_line;
	
	// ....
	
	index = ft_strlen(ft_strchr(buf, '\n'));
	if (!buf[index])
	{
		free(buf);
		return (0);
	}
	line_keep = malloc(ft_strlen(buf) - index + 1);
	index++;
	j = 0;
	while (buf[index])
	{
		line_keep[j] = buf[index];
		j++;
		index++;
	}
	line_keep = 0;
	free(buf);
	keep[fd] = line_keep;
	
	// ...
	
	if (n_read == 0)
		return (0);
	else
		return(1);
}
