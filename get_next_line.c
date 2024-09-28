/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalshish <yalshish@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:33:29 by yalshish          #+#    #+#             */
/*   Updated: 2024/09/25 18:02:20 by yalshish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;


	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

}

#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	close(fd);
	return (0);
}