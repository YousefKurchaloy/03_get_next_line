/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurchaloy <kurchaloy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:15:35 by yalshish          #+#    #+#             */
/*   Updated: 2024/12/11 12:26:36 by kurchaloy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char **str)
// this function is used to free the memory allocated by reference
// to the pointer passed as an argument and set the pointer to NULL
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_storage(char *line)
{
	char	*new_line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(line, '\n');
	if (!ptr)
	{
		new_line = NULL;
		return (ft_free(&line));
	}
	else
		len = (ptr - line) + 1;
	if (!line[len])
		return (ft_free(&line));
	new_line = ft_substr(line, len, ft_strlen(line) - len);
	ft_free(&line);
	if (!new_line)
		return (NULL);
	return (new_line);
}

char	*new_buf(char *line)
{
	char	*buf;
	char	*ptr;
	int		len;

	ptr = ft_strchr(line, '\n');
	len = (ptr - line) + 1;
	buf = ft_substr(line, 0, len);
	if (!buf)
		return (NULL);
	return (buf);
}

char	*read_buffer(int fd, char *line)
{
	int		byte;
	char	*buffer;

	byte = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&line));
	buffer[0] = '\0';
	while (byte > 0 && !ft_strchr(buffer, '\n'))
	{
		byte = read (fd, buffer, BUFFER_SIZE);
		if (byte > 0)
		{
			buffer[byte] = '\0';
			line = ft_strjoin(line, buffer);
		}
	}
	free(buffer);
	if (byte == -1)
		return (ft_free(&line));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line = {NULL};
	char		*buf;

	if (fd < 0)
		return (NULL);
	if ((line && !ft_strchr(line, '\n')) || !line)
		line = read_buffer (fd, line);
	if (!line)
		return (NULL);
	buf = new_buf(line);
	if (!buf)
		return (ft_free(&line));
	line = clean_storage(line);
	return (buf);
}
