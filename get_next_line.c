/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paangulo <paangulo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:18:06 by paangulo          #+#    #+#             */
/*   Updated: 2024/08/22 18:46:00 by paangulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*new_line;

	if (fd < 0 || line == NULL)
		return (NULL);
}

//funcion que lee del fd y va guardando en buf que es un buffer temporal
char	*readline(int fd, char *buf)
{
	char	*line;
	int		count;
	
	count = -3;
	line = strdup (buf);
	
}
