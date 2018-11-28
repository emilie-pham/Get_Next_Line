/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:43:18 by epham             #+#    #+#             */
/*   Updated: 2018/11/28 13:26:48 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("test", O_RDONLY);
	if (fd != (-1))
		while (get_next_line(fd, &line) == 1)
			printf("%s\n", line);
	free(line);
	return (0);
}