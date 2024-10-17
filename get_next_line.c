/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalshish <yalshish@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:33:29 by yalshish          #+#    #+#             */
/*   Updated: 2024/10/14 19:54:26 by yalshish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char *get_joined_buffer(char *buffer, int fd)
{
	char temp[BUFFER_SIZE + 1];
	long i;

	i = -1;
	while (++i <= BUFFER_SIZE)
		temp[i] = '\0';
	i = 1;
	while (!ft_strchr(temp, '\n') && i)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0 || (!i && !buffer))
			return (NULL);
		temp[i] = '\0';
		if (!buffer)
			buffer = ft_strdup(temp);
		else
			buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *ret_line;
	char *temp;
	int i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = get_joined_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		++i;
	if (buffer[i] == '\n')
		++i;
	ret_line = ft_substr(buffer, 0, i);
	temp = ft_substr(buffer, i, ft_strlen(buffer) - i);
	free(buffer);
	buffer = temp;
	return (ret_line);
}

#include <stdio.h>
int main(void)
{
	int fd;

	fd = open("test01.txt", O_RDONLY);

	printf("1> %s", get_next_line(fd));
	printf("2> %s", get_next_line(fd));
	printf("3> %s", get_next_line(fd));
	return (0);
}