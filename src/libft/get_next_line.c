/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:58:41 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/06 13:30:42 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"

t_fdbuf	*get_fdbuf(t_list **lst, const int fd)
{
	t_fdbuf	*ptr;

	while (*lst && fd != ((t_fdbuf*)((*lst)->content))->fd)
		lst = &((*lst)->next);
	if (!*lst)
	{
		ptr = (t_fdbuf*)malloc(sizeof(t_fdbuf));
		if (!ptr)
			return (0);
		ptr->fd = fd;
		ptr->buf = (char*)malloc(BUFF_SIZE + 1);
		if (!(ptr->buf))
			return (0);
		if (-1 == (ptr->eof = read(fd, ptr->buf, BUFF_SIZE)))
			return (0);
		(ptr->buf)[BUFF_SIZE] = 0;
		ptr->i = 0;
		*lst = ft_lstnew(ptr, sizeof(t_fdbuf));
		free(ptr);
	}
	if (!*lst)
		return (0);
	return ((*lst)->content);
}

int		expand_str(char **str, int *str_size)
{
	char	*tmp;

	*(*str + STR_UNIT_SIZE * *str_size) = 0;
	(*str_size)++;
	tmp = (char*)malloc(STR_UNIT_SIZE * *str_size + 1);
	if (!tmp)
		return (-1);
	ft_strcpy(tmp, *str);
	free(*str);
	*str = tmp;
	return (0);
}

char	*get_line(t_fdbuf *fdbuf, char *buf, int i, int str_size)
{
	char	*str;
	int		j;

	if (!(str = (char*)malloc(STR_UNIT_SIZE + 1)))
		return (0);
	j = 0;
	while (buf[i] != '\n' && i < fdbuf->eof)
	{
		str[j++] = buf[i++];
		if (i == BUFF_SIZE)
		{
			if (-1 == (fdbuf->eof = read(fdbuf->fd, buf, BUFF_SIZE)))
				return (0);
			i = 0;
		}
		if (j == STR_UNIT_SIZE * str_size)
			if (expand_str(&str, &str_size))
				return (0);
	}
	str[j] = 0;
	if (fdbuf->buf != buf)
		free(fdbuf->buf);
	fdbuf->buf = buf;
	fdbuf->i = (buf[i] == '\n') ? ++i : i;
	return (str);
}

int		check_if_fd_empty(int fd, t_fdbuf *fdbuf, char **line)
{
	if ((fdbuf->eof = read(fd, fdbuf->buf, BUFF_SIZE)) > 0)
	{
		fdbuf->i = 0;
		return (get_next_line(fd, line));
	}
	if (!*line)
		*line = (char*)malloc(STR_UNIT_SIZE + 1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_fdbuf			*fdbuf;
	int				str_size;

	if (fd < 0 || !line)
		return (-1);
	if (!(fdbuf = get_fdbuf(&lst, fd)))
		return (-1);
	if (fdbuf->eof <= fdbuf->i)
		return (check_if_fd_empty(fd, fdbuf, line));
	str_size = 1;
	*line = get_line(fdbuf, fdbuf->buf, fdbuf->i, str_size);
	if (!*line)
		return (-1);
	if (fdbuf->i == BUFF_SIZE)
	{
		if (-1 == (fdbuf->eof = read(fdbuf->fd, fdbuf->buf, BUFF_SIZE)))
			return (-1);
		fdbuf->i = 0;
	}
	return (1);
}
