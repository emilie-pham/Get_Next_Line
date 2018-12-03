/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:13:03 by epham             #+#    #+#             */
/*   Updated: 2018/12/03 15:23:31 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main(int ac, char **av)
{
	(void)ac;
	int	fd = 0;
	char *line = NULL;

	fd = open(av[1], O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{
	   dprintf(1, "%s\n", line);
	   free(line);	
	}
}