/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:39:34 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/09 17:11:39 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

int		main(int ac, char **av)
{
	char	*src;
	char	**arr_tet;
	char	**board;
	int		board_size;

	if (ac != 2)
	{
		write(1, "usage: fillit source_file\n", 26);
		return (-1);
	}
	if (!(src = get_src(av[1])))
		print_error();
	if (!(arr_tet = parse_src(src)))
		print_error();
	free(src);
	board_size = get_smallest_size(arr_tet);
	board = make_board(board_size);
	while (!fillit(arr_tet, board, board_size, 0))
	{
		free_board(board, board_size);
		board = make_board(++board_size);
	}
	print_board(board, board_size);
	return (0);
}
