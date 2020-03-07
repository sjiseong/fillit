/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:42:32 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/06 15:57:41 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	print_error(void)
{
	write(1, "error\n", 6);
	exit(-1);
}

void	print_board(char **board, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, board[i], size);
		write(1, "\n", 1);
		i++;
	}
}
