/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:43:18 by epham             #+#    #+#             */
/*   Updated: 2018/12/01 16:11:03 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main(void)
{
	int		fd;
	int		fd2;
	int		ok;
	char	*line;

	line = NULL;
	fd = open("test", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	if (fd != (-1) && fd2 != (-1))
		while (1)
		{
			ok = 1;
			if (get_next_line(fd, &line))
				printf("line test1 : %s$\n", line);
			if (get_next_line(fd2, &line))
			{
				printf("line test2 : %s$\n", line);
				ok = 1;
			}
			else
				ok = 0;
			if (!ok)
				break ;
		}
	free(line);
	return (0);
}
