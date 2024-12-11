/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalshish <yalshish@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:15:35 by yalshish          #+#    #+#             */
/*   Updated: 2024/12/12 01:27:49 by yalshish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// This function is used to free the address:
// of the pointer passed as an argument.
// and set the pointer to NULL.
// It has a return type of void* to be able to return NULL.
void	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

// This function is used to find the first '\n' of a character in a string.
// then subtract the address of the first character in the string
// from the address of the first occurrence of '\n'.
// then +1 to include the '\n' character.
// this method of subtraction is used to find the length of the string.
// which is much faster than using strlen.(itterating through the string)
// if the character at index len is not found, the function returns NULL.
// and frees the memory of line.
// otherwise, it returns new_line.
// new_line is the line from the '\n' to the next '\n'.
// then the line is freed. And the new_line is returned.
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

// This function creates a new buffer of size len.
// len is the length that was found by subtracting addresses.
// The addresses subtracted:
// The address of the first occurrence of a newline character.
// The address of the first character in the line.
// The + 1 is to include the newline character.
// Then using the ft_substr function to copy the line into buf.
// If the allocation fails, the function returns NULL.
// Otherwise, it returns buf.
char	*new_buffer(char *line)
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

// This function reads from the file descriptor and returns the line.
// It allocates a buffer of size BUFFER_SIZE + 1.
// The buffer is initialized to an empty string.
// The function reads from the file descriptor until it reaches '\n'.
char	*read_buffer(int fd, char *line)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free(&line));
	buffer[0] = '\0';
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read (fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			line = ft_strjoin(line, buffer);
			if (!line)
				break ;
		}
	}
	free(buffer);
	if (bytes_read == -1)
		return (ft_free(&line));
	return (line);
}

// This function reads the file descriptor and returns the next line.
// File descriptors are non-negative unique integers.
// The operating system assigns the lowest available file descriptor
// to a newly opened file.
// The file descriptor is used by the program
// to interact with files, sockets, input/output (I/O) resources,
// when performing read, write, or other operations.
// The function initializes a static variable line to NULL.
// Static variable meaning that,
// its lifetime is the entire run of the program.
// The function calles read_buffer to read from the file descriptor
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
	buf = new_buffer(line);
	if (!buf)
		return (ft_free(&line));
	line = clean_storage(line);
	return (buf);
}
