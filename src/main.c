/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:39:34 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/06 15:55:49 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

int		main(int ac, char **av)
{
	char	*src;
	t_list	*lst;
	char	**board;
	int		board_size;
	int		ret;

	if (ac != 2)
	{
		write(1, "usage: fillit source_file\n", 26);
		return (-1);
	}
	if (!(src = get_src(av[1])))
		print_error();
	if (!(lst = parse_src(src)))
		print_error();
	ret = 0;
	board_size = get_smallest_size(lst);
	while (!ret)
	{
		board = make_board(board_size);
		ret = fillit(lst, board, board_size);
		board_size++;
	}
	print_board(board, --board_size);
	return (0);
}
