/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:39:34 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/07 21:12:23 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

void	check_arg_num(int ac)
{
	if (ac != 2)
	{
		write(1, "usage: fillit source_file\n", 26);
		print_error();
	}
}

int		main(int ac, char **av)
{
	char	*src;
	int		**arr_tet;
	char	**board;
	int		board_size;
	int		*order;
	
	check_arg_num(ac);
	if (!(src = get_src(av[1])))
		print_error();
	if (!(arr_tet = parse_src(src)))
		print_error();
	board_size = get_smallest_size(arr_tet);
	board = make_board(board_size);
	order = (int*)malloc(sizeof(int) * 27);
	ft_memset(order, -1, 26 * sizeof(int));
	order[26] = 0;
	while (!fillit(arr_tet, board, board_size, order))
		board = make_board(++board_size);
	print_board(board, board_size);
	return (0);
}
