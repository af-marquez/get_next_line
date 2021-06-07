#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	//keeps the position
	static char	*keep[1024];
	//keeps the line read
	char		*buf;
	//nr of lines read
	int 		n_read;

	if (!line || (read(fd, 0 ,0) == -1) || BUFFER_SIZE < 1)
		return (-1);
	// n_read = -1 error , zero EOF or 1 line read

	// this section reads the line when doesnt have \n 
	
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
	*line = first_trt(keep[fd]);
	keep[fd] = second_trt(keep[fd]);
		
	//..
	
	if (n_read == 0)
		return (0);
	else
		return(1);
}
	

	