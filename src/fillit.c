/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aksuleim <aksuleim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:36:30 by aksuleim          #+#    #+#             */
/*   Updated: 2020/03/06 16:41:15 by aksuleim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

void	board_cpy(char	**board, char **tmp);
int		ft_is_free(char **board, int *address, int x, int y, int j, int board_size);
int		fillit(t_list *lst, char **board, int board_size);
void	free_board(char **board);
char	**make_board(int board_size);

int		get_smallest_size(t_list *lst)
{
	int		count;
	int		ret;

	count = 0;
	ret = 2;
	while (lst->next)
	{
		lst = lst->next;
		count++;
	}
	while (ret * ret < count)
		ret++;
	return (ret);
}

int		fillit(t_list *lst, char **board, int board_size)
{
	int		i;
	int		*address;
	int		j;
	int		x;
	int		y;

	i = -1;
	address = malloc(sizeof(int) * 4);
	if (!lst->content)
		return (1);
	while (++i * 4 < board_size * board_size)
	{
		j = 0;
		x = 0;
		y = 0;
		address = (int *)(lst->content);
		if (ft_is_free(board, address, x, y, j, board_size))
		{

		}
	}
	// return (fillit(lst->next, board_size, board));
	return (0);
}

int		ft_is_free(char **board, int *address, int x, int y, int j, int board_size)
{
	int		next;
	int		curr;
	char	**tmp;

	tmp = NULL;
	while (j < 4)
	{
		curr = address[j];
		next = address[j + 1];
		board_cpy(board, tmp);
		if (board[y][x] == '.')
		{
			tmp[y][x] = '#';
			return (ft_is_free(board, address, x + next % 4 - curr % 4, y + next / 4 - curr / 4, j++, board_size));
			free_board(tmp);
		}
		else if (x < board_size)
			return (ft_is_free(board, address, x++, y, j--, board_size));
		else if (x >= board_size && y < board_size)
		{
			x = 0;
			return (ft_is_free(board, address, x, y++, j--, board_size));
		}
		else
			return (-1);
	}
	return (0);
}

void	board_cpy(char	**board, char **tmp)
{
	int		i;
	int		j;

	i = -1;
	while (board[++i])
	{
		j = -1;
		while (board[i][++j])
			tmp[i][j] = board[i][j];
	}
}

void	free_board(char **board)
{
	int		i;
	int		j;

	i = -1;
	while (board[++i])
	{
		j = -1;
		while (board[i][++j])
			board[i][j] = '.';
	}
}

char	**make_board(int board_size)
{
	char	**str;
	int		i;
	int		j;

	i = -1;
	str = (char **)malloc(sizeof(char *) * board_size);
	while (++i < board_size)
		str[i] = (char *)malloc(sizeof(char) * board_size);
	str[i] = NULL;
	i = -1;
	j = 0;
	while (++i < board_size)
		while (j < board_size)
			str[i][j++] = '.';
	return (str);
}

// int		main(int ac, char **av)
// {
// 	int		size;
// 	char	**str;
// 	t_list	lst;

// 	size = ft_smallest_sqr(number_hash);
// 	fillit(lst, size, str);
// }