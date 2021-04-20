/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:13 by amarquez          #+#    #+#             */
/*   Updated: 2021/04/20 20:47:05 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_next_line(int fd, char **line)
{
	//guarda posição onde é lido
	static char	*keep[2048];
	//mantem linha lida e vai ser junta com a linha salva
	char		*buf_temp[BUFFER_SIZE + 1];
	//conta nr linhas lidas
	int 		n_read;
	
	if (!line || (read(fd, 0 ,0) == -1) || BUFFER_SIZE < 1 || !buf_temp)
		return (-1);
	// n_read = -1 erro , zero EOF ou 1 linha lida
	
	// determinar se é linha ou nao
	while (ft_strchr(keep[fd], '\n') == 0)
	{
		n_read = read(fd, buf_temp, BUFF_SIZE)
		if (n_read == -1)
		{
			free(buf_temp);
			return(-1);
		}
		buf_temp[n_read] = '\0';

		if (
	ft_strchr(keep[fd], '\n');
	//se sim copiar str no keep[fd]
	//*line = até \n
	//keep[fd] = depois de \n

	
	
	// se nao for linha uma funcao le o file com o mesmo tamanho
	return ();
}
