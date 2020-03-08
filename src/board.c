/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:33:40 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/07 23:53:52 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_smallest_size(char **arr_tet)
{
	int		cnt;
	int		ret;

	cnt = 0;
	ret = 2;
	while (arr_tet[cnt])
		cnt++;
	cnt *= 4;
	while (ret * ret < cnt)
		ret++;
	return (ret);
}

char	**alloc_board(int board_size)
{
	char	**board;
	int		i;

	i = -1;
	board = (char **)malloc(sizeof(char *) * board_size);
	while (++i < board_size)
		board[i] = (char *)malloc(sizeof(char) * board_size);
	return (board);
}

char	**make_board(int board_size)
{
	char	**board;
	int		i;
	int		j;

	board = alloc_board(board_size);
	i = -1;
	while (++i < board_size)
	{
		j = 0;
		while (j < board_size)
			board[i][j++] = '.';
	}
	return (board);
}

void	copy_board(char **cur, char **new, int bsize)
{
	int		i;
	int		j;
	char	*p1;
	char	*p2;

	i = -1;
	while (++i < bsize)
	{
		j = bsize;
		p1 = cur[i];
		p2 = new[i];
		while (j-- > 0)
			*p2++ = *p1++;
	}
}

void	free_board(char **board, int bsize)
{
	int	i;

	i = 0;
	while (i < bsize)
		free(board[i++]);
	free(board);
}
