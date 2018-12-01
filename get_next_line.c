/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:59:05 by epham             #+#    #+#             */
/*   Updated: 2018/12/01 16:29:33 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*ft_link_select(t_list **list, int fd)
{
	t_list	*newlink;

	if (!*list)
		*list = ft_lstnew("\0", fd);
	newlink = *list;
	while (newlink)
	{
		if ((int)newlink->content_size == fd)
			return (newlink);
		newlink = newlink->next;
	}
	newlink = ft_lstnew("\0", fd);
	ft_lstadd(list, newlink);
	return (newlink);
}

char	*ft_joinfree(char *content, char *buff)
{
	char	*temp;

	temp = content;
	content = ft_strjoin(content, buff);
	free(temp);
	return (content);
}

char	*ft_dupfree(char *content, int i)
{
	char	*temp;

	temp = content;
	content = ft_strdup(content + i + 1);
	free(temp);
	return (content);
}

int		get_next_line(const int fd, char **line)
{
	char				buff[BUFF_SIZE + 1];
	int					size;
	static t_list		*list;
	t_list				*current;
	int					i;

	if (fd < 0 || read(fd, buff, 0) < 0 || !line)
		return (-1);
	current = ft_link_select(&list, fd);
	while ((size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[size] = '\0';
		current->content = ft_joinfree(current->content, buff);
		if (ft_strchr(current->content, '\n') != NULL)
			break ;
	}
	if (ft_strlen(current->content) == 0 || !current->content)
		return (0);
	if (ft_strchr(current->content, '\n') != NULL)
	{
		i = 0;
		while (((char *)(current->content))[i] != '\n')
			i++;
		*line = ft_strsub(current->content, 0, i);
		current->content = ft_dupfree(current->content, i);
		return (1);
	}
	if (size < BUFF_SIZE)
	{
		buff[size] = '\0';
		current->content = ft_joinfree(current->content, buff);
		*line = ft_strdup(current->content);
		ft_strclr(current->content);
	}
	return (1);
}
