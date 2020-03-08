/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aksuleim <aksuleim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:57:02 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/07 21:12:46 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
**	parse_source.c
*/

char	*get_src(char *filename);
int		**parse_src(char	*src);

/*
**	board.c
*/

int		get_smallest_size(int **arr_tet);
char	**alloc_board(int board_size);
char	**make_board(int board_size);
void	copy_board(char **cur, char **new, int board_size);
void	free_board(char **board, int board_size);

/*
**	fillit.c
*/

int		fillit(int **arr_tet, char **board, int board_size, int *order);

/*
**	order.c
*/

int		is_in_order(int i, int *order);
void	add_in_order(int i, int *order);
void	revert_order(int i, int *order);
int		get_order_len(int *order);

/*
**	print.c
*/

void	print_board(char **board, int board_size);
void	print_error(void);
#endif
