/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:47:13 by amarquez          #+#    #+#             */
/*   Updated: 2021/04/08 11:32:07 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//	Funcao retorna 1 quando foi lido, 0 quando EOF e -1 se deu erro
//	Enquanto nao atingir EOF, para guardar linha usar static variable com o BUFFER_SIZE ate o prog. terminar;
//Implementacao:
//gtl vai ler um ficheiro usando o BUFFERsize e determinar se e' linha ou nao
//se n~ for uma linha, a funcao vai ler a mesma qtd novamente
//Open max e' o nr maximo de files abertos simultaneamente
//Vai mant
//	
int	get_next_line(int fd, char **line)
{
	
}
