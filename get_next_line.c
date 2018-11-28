/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:59:05 by epham             #+#    #+#             */
/*   Updated: 2018/11/28 15:19:05 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	char				buff[BUFF_SIZE + 1];
	int					size;
	char				*temp;
	static t_list		*list;
	int					i;


	if (fd < 0 || read(fd, buff, 0) < 0 || !line)
		return (-1);
	if (!list)
		list = ft_lstnew("\0", 1);
	while ((size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[size] = '\0';
		temp = list->content;
		list->content = ft_strjoin(list->content, buff);
		free(temp);
		if (ft_strchr(buff, '\n') != NULL)
			break;
	}
	if (ft_strchr(list->content, '\n') != NULL)
	{
		i= 0;
		while (((char *)(list->content))[i] != '\n')
			i++;
		*line = ft_strsub(list->content, 0, i);
		list->content = list->content + i + 1;
//		printf("line : %s$\n", *line);
//		printf("list->content : %s\n", (char *)list->content);
		return (1);
	}
	if (ft_strchr(buff, '\0') != NULL)
	{
		buff[size] = '\0';
		temp = list->content;
		list->content = ft_strjoin(list->content, buff);
		*line = ft_strjoin(list->content, ft_strsub(buff, 0, size));
//		printf("line : %s$\n", *line);
		ft_strclr(list->content);
		free(temp);
	}
	return (0);
}
