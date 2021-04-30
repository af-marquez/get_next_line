/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:13 by amarquez          #+#    #+#             */
/*   Updated: 2021/04/30 01:42:39 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	//guarda posição onde é lido
	static char	*keep[1024];
	//mantem linha lida e vai ser junta com a linha salva
	char		*buf;
	//conta nr linhas lidas
	int 		n_read;
	char 		*new_line;
	int 		index;
	char		*line_keep;
	int			j;

	if (!line || (read(fd, 0 ,0) == -1) || BUFFER_SIZE < 1)
		return (-1);
	// n_read = -1 erro , zero EOF ou 1 linha lida
	

	// esta parte lida quando nao existe o \n na parte a ser lida 
	
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	n_read = 1;
	while (ft_strchr(keep[fd], '\n') == 0 && n_read != 0)
	{
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read == -1)
		{
			free (buf);
			return(-1);
		}
		buf[n_read] = '\0';
		keep[fd] = ft_strjoin(keep[fd],buf);
	}
	free(buf);
	// .... Esta parte lida com o que vem antes do fim de linha	
	index = 0;
	while (keep[index] != '\n' && keep[index])
	{
		index++;
	}
	new_line = (char *)malloc(sizeof(char) * (index + 1));
	if (!new_line)
		return (0);
	index = 0;
	while (keep[index] != '\n' && keep[index])
	{
		new_line[index] = keep[index];
		index++;
	}
	new_line[index] = '\0';
	*line = new_line;
	
	// .... esta parte lida com o que vem depois do fim de linha
	
	index = 0;
	while (keep[index] != '\n' && keep[index])
	{
		index++;
	}
	if (!keep[index])
	{
		free (buf);
		return (0);
	}
	line_keep = malloc(sizeof(char) * (ft_strlen(keep) - index + 1));
	if (!line_keep)
		return (0);
	index++;
	j = 0;
	while (keep[index])
	{
		line_keep[j++] = keep[index++];
	}
	line_keep[j] = '\0';
	free (keep);
	keep[fd] = line_keep;
		
	// ... isto devolve o número devido
	
	if (n_read == 0)
		return (0);
	else
		return(1);
}
