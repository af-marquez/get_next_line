/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:13 by amarquez          #+#    #+#             */
/*   Updated: 2021/05/01 19:06:43 by ipenas           ###   ########.fr       */
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
	char		*tmp;

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
		tmp = ft_strjoin(keep[fd],buf);
		free(keep[fd]);
		keep[fd] = tmp;
	}
	free(buf);
	// .... Esta parte lida com o que vem antes do fim de linha e lanca parao pointer do GNL
	*line = first_trt(keep[fd]);
	// .... esta parte lida com o que vem depois do fim de linha
	keep[fd] = second_trt(keep[fd]);
	// ... isto devolve o número devido
	if (n_read == 0)
		return (0);
	else
		return(1);
}
