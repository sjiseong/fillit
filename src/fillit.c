/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aksuleim <aksuleim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:36:30 by aksuleim          #+#    #+#             */
/*   Updated: 2020/03/07 21:15:02 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

#include <stdio.h>

static int	fill_one_block(int pos, char **board, int params[3], char c, int xy[2])
{
	int	x;
	int	y;
	int	bsize;
	int	i;
	int	std;

	bsize = params[0];
	i = params[1];
	std = params[2];
	x = i % bsize + pos % 4 - std % 4;
	y = i / bsize + pos / 4 - std / 4;
	if (x < 0 || x >= bsize || y < 0 || y >= bsize || board[y][x] != '.')
		return (0);
	board[y][x] = c;
	xy[0] = x;
	xy[1] = y;
	return (1);
}

static int	fill_one_tet(int *tet, char **board, int bsize, char c, int i)
{
	int	arr[4][2];
	int	j;
	int	params[3];

	params[0] = bsize;
	params[1] = i;
	params[2] = tet[0];
	j = -1;
	while (++j < 4)
		if (!fill_one_block(tet[j], board, params, c, arr[j]))
			break ;
	if (j == 4)
		return (1);
	while (j-- > 0)
		board[arr[j][1]][arr[j][0]] = '.';
	return (0);
}

int			fillit(int **arr_tet, char **board, int board_size, int *order)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	tmp = make_board(board_size);
//	printf("before :\n");
//	print_board(board, board_size);
//	printf("\n");
	while (arr_tet[++i])
	{
		if (is_in_order(i, order))
			continue;
		copy_board(board, tmp, board_size);
		add_in_order(i, order);
		j = -1;
		while (j++ < board_size * board_size)
			if (fill_one_tet(arr_tet[i], board, board_size, i + 'A', j))
			{
				if (fillit(arr_tet, board, board_size, order))
				{
					free_board(tmp, board_size);
					return (1);
				}
				copy_board(tmp, board, board_size);
			}
		revert_order(i, order);
	}
//	printf("after :\n");
//	print_board(board, board_size);
//	printf("\n");
	free_board(tmp, board_size);
	if (get_order_len(order) == i)
		return (1);
	return (0);
}
