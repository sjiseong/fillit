/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_source.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:34:17 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/08 00:03:44 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

char		*get_src(char *filename)
{
	int		fd;
	int		ret;
	char	*buf;

	if (-1 == (fd = open(filename, O_RDONLY)))
		return (0);
	buf = (char*)malloc(1024);
	if (!buf)
		return (0);
	ft_bzero(buf, 1024);
	ret = read(fd, buf, 1024);
	close(fd);
	if (ret < 20 || ret > 545)
		return (0);
	buf[ret] = 0;
	return (buf);
}

static	int	parse_tet(char *src, char *tet, int i, int nblock)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			if (src[i] == '#')
				if (nblock >= 4)
					return (-1);
				else
					(tet[nblock++] = x * 4 + y);
			else if (src[i] != '.')
				return (-1);
			i++;
		}
		if (src[i++] != '\n')
			return (-1);
	}
	if ((src[i] != '\n' && src[i] != 0) || (src[i] == '\n' && !src[i + 1]))
		return (-1);
	return (nblock);
}

static	int	check_tet(char *tet)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	check;

	i = -1;
	check = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			x = tet[j] % 4 - tet[i] % 4;
			y = tet[j] / 4 - tet[i] / 4;
			x = x < 0 ? -x : x;
			y = y < 0 ? -y : y;
			if ((x == 1 && y == 0) || (x == 0 && y == 1))
				check += 1;
		}
	}
	if (check < 6)
		return (0);
	return (1);
}

char		**parse_src(char *src)
{
	char	**arr_tet;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr_tet = (char**)malloc(sizeof(char*) * 27);
	while (src[j * 21])
	{
		arr_tet[j] = (char*)malloc(sizeof(char) * 4);
		if (parse_tet(src + j * 21, arr_tet[j], i, 0) != 4)
			print_error();
		if (!check_tet(arr_tet[j]))
			print_error();
		j++;
	}
	arr_tet[j] = 0;
	return (arr_tet);
}
