/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patri <patri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:18:06 by paangulo          #+#    #+#             */
/*   Updated: 2024/09/15 15:03:55 by patri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//funcion que lee del fd y va guardando en buf que es un buffer temporal
char	*readline(int fd, char *buf)
{
	char	*line;
	int		number_bytes_read;

	number_bytes_read = -2;
	line = ft_strdup (buf);
	while (!(ft_strchr(line, '\n')) && number_bytes_read != 0)
	{
		number_bytes_read = read(fd, buf, BUFFER_SIZE);
		if (number_bytes_read == -1)
		{
			free(line);
			return (NULL);
		}
		buf[number_bytes_read] = '\0';
		line = ft_strjoin(line, buf, number_bytes_read);
	}
	return (line);
}

//buf: para almacenar los datos que quedan por leer tras leer line.
//line: línea completa leída hasta ahora (incluye todo hasta \n o EOL)
//new_line: Puntero a la posición de nueva línea \n en line si la hay

void	prepare_buffer(char *buf, char *line, char *new_line)
{
	int	number_bytes_copy;

	if (new_line != NULL)
	{
		number_bytes_copy = new_line - line + 1;
		ft_strlcpy(buf, new_line + 1, BUFFER_SIZE + 1);
	}
	else
	{
		number_bytes_copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	line[number_bytes_copy] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*new_line;

	line = readline(fd, buf);
	if (fd < 0 || line == NULL)
		return (NULL);
	if (!line || ft_strlen(line) == 0)
	{
		free (line);
		return (NULL);
	}
	new_line = ft_strchr(line, '\n');
	prepare_buffer(buf, line, new_line);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		fd;

	fd = open("prueba.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf ("%s", line);
		free (line);
	}
	close (fd);
	return (0);
}*/
