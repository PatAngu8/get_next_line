/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paangulo <paangulo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:18:06 by paangulo          #+#    #+#             */
/*   Updated: 2024/09/06 12:42:18 by paangulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//funcion que lee del fd y va guardando en buf que es un buffer temporal
char	*readline(int fd, char *buf)
{
	char	*line;
	int		count; //almacenará nº de bytes o caracteres leídos	
	count = -3;
	line = ft_strdup (buf);//Esto es lo mismo que lo siguiente (hasta return (line)):
	/*line = malloc(ft_strlen(buf)) * sizeof(char);
	if (!buf)
		return (NULL);
	ft_strcpy(buf, line);
	return (line);*/
	while (!(ft_strchr(line, '\n')) && count != 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
		{
			free(line);
			ft_bzero(buf, BUFFER_SIZE + 1);
			return (NULL);
		}
		buf[count] = '\0';
		line = ft_strjoin(line, buf, count);
	}
	return (line);
}

//prepara el contenido del buffer buf después de leer una línea en la función gnl
void	prepare_buffer(char *buf, char *line, char *new_line)
{
	int	copy;
	//buf: El buffer estático que se utiliza para almacenar los datos leídos del archivo
	//line: línea completa leída hasta ahora (incluye todo lo del bufer hasta \n o EOL)
	//new_line: Puntero a la posición de nueva línea \n en line si la hay. Si no, new_line = null
	if (new_line != NULL)
	{
		copy = new_line - line + 1;
		ft_strlcpy(buf, new_line + 1, BUFFER_SIZE + 1);
	}
	else
	{
		copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	line[copy] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*new_line;

	if (fd < 0 || line == NULL)
		return (NULL);
	line = readline(fd, buf);
	if (!line || ft_strlen(line) == 0)
	{
		free (line);
		return (NULL);
	}
	new_line = ft_strchr(line, '\n');
	prepare_buffer(buf, line, new_line);
	return (line);
}
