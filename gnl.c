/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:59:05 by epham             #+#    #+#             */
/*   Updated: 2018/11/28 15:28:36 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_isnewline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	char			*temp;
	static t_list	*list;
	int				size;
	int				i;

	if (fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (!list)
		list = ft_lstnew("\0", 1);
	while ((size = read(fd, buff, BUFF_SIZE)) > 0 && ft_strchr(buff, '\n') == NULL)
	{
		buff[size] = '\0';
		temp = list->content;
		list->content = ft_strjoin(list->content, buff);
		free(temp);
	}
	while (size > 0 && (ft_strchr(list->content, '\n') != NULL || ft_strchr(buff, '\n') != NULL))
	{
		list->content = ft_strjoin(list->content, buff);
		i = 0;
		while (((char *)(list->content))[i] != '\n')
			i++;
		*line = ft_strsub(list->content, 0, i);
		list->content = ft_strsub(list->content, i + 1, ft_strlen(list->content));
		return (1);
	}
	return (0);
}
