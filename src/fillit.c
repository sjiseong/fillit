/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aksuleim <aksuleim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:36:30 by aksuleim          #+#    #+#             */
/*   Updated: 2020/03/07 12:40:50 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

void	board_cpy(char	**board, char **tmp);
int		ft_is_free(char **board, int *address, int x, int y, int j, int board_size);
int		fillit(int **arr_tet, char **board, int board_size);
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


int		fillit(int **arr_tet, char **board, int board_size)
{
	int	i;

	tet = malloc(sizeof(int) * 4);
	i = 0;
	while (arr_tet[i])
	{
		fillit(arr_tet, 
	}
}

/*
int		fillit(t_list *lst, char **board, int board_size)
{
	int		i;
	int		*tet;
	i = -1;
	x = 0;
	y = 0;
	j = 0;
	if (!lst->content)
		return (1);
	while (++i * 4 < board_size * board_size)
	{
		address = (int *)(lst->content);		
		ft_is_free(board, address, x, y, j, board_size);
		x++;
		y++;
		j++;
		return (fillit(lst->next, board, board_size));
	}
	return (0);
}
*/

int		ft_is_free(char **board, int *address, int x, int y, int j, int board_size, int temp_x, int temp_y)
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
		if (board[temp_y][temp_x] == '.')
		{
			tmp[temp_y][temp_x] = '#';
			return (ft_is_free(board, address, x, y , j++, board_size, x + next % 4 - curr % 4, y + next / 4 - curr / 4));
			free_board(tmp);
		}
		else if (x < board_size)
			return (ft_is_free(board, address, x, y, 0, board_size, x++, y));
		else if (x >= board_size && y < board_size)
		{
			return (ft_is_free(board, address, x, y, 0, board_size, 0, y++));
		}
		else
			return (-1);
	}
	board_cpy(tmp, board);
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
