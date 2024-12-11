/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurchaloy <kurchaloy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:27:09 by kurchaloy         #+#    #+#             */
/*   Updated: 2024/12/11 12:28:17 by kurchaloy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("test3.txt", O_RDONLY);
	printf("1> %s", get_next_line(fd));
	printf("2> %s", get_next_line(fd));
	printf("3> %s", get_next_line(fd));
	return (0);
}
