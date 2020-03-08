/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aksuleim <aksuleim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:36:30 by aksuleim          #+#    #+#             */
/*   Updated: 2020/03/07 23:56:46 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static int	fill_one_block(int pos, char **board, int params[4], int xy[2])
{
	int	x;
	int	y;
	int	bsize;
	int	i;
	int	std;

	bsize = params[0];
	i = params[2];
	std = params[3];
	x = i % bsize + pos % 4 - std % 4;
	y = i / bsize + pos / 4 - std / 4;
	if (x < 0 || x >= bsize || y < 0 || y >= bsize || board[y][x] != '.')
		return (0);
	board[y][x] = params[1] + 'A';
	xy[0] = x;
	xy[1] = y;
	return (1);
}

static int	fill_one_tet(char *tet, char **board, int params[4], int i)
{
	int	arr[4][2];
	int	j;

	params[1] = i;
	params[3] = tet[0];
	j = -1;
	while (++j < 4)
		if (!fill_one_block(tet[j], board, params, arr[j]))
			break ;
	if (j == 4)
		return (1);
	while (j-- > 0)
		board[arr[j][1]][arr[j][0]] = '.';
	return (0);
}

int			fillit(char **arr_tet, char **board, int board_size, int i)
{
	int		j;
	char	**tmp;
	int		params[4];

	if (!arr_tet[i])
		return (1);
	tmp = alloc_board(board_size);
	copy_board(board, tmp, board_size);
	j = -1;
	params[0] = board_size;
	while (++j < board_size * board_size)
	{
		params[2] = j;
		if (fill_one_tet(arr_tet[i], board, params, i))
		{
			if (fillit(arr_tet, board, board_size, i + 1))
			{
				free_board(tmp, board_size);
				return (1);
			}
			copy_board(tmp, board, board_size);
		}
	}
	free_board(tmp, board_size);
	return (0);
}
