/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalshish <yalshish@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:33:29 by yalshish          #+#    #+#             */
/*   Updated: 2024/09/22 16:13:58 by yalshish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	char	*line;

	i = 0;

	read(fd, line, BUFFER_SIZE);
	return (line);
}

#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	close(fd);
	return (0);
}