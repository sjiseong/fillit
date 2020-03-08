/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aksuleim <aksuleim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:57:02 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/07 23:39:24 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
**	parse_source.c
*/

char	*get_src(char *filename);
char	**parse_src(char	*src);

/*
**	board.c
*/

int		get_smallest_size(char **arr_tet);
char	**alloc_board(int board_size);
char	**make_board(int board_size);
void	copy_board(char **cur, char **new, int board_size);
void	free_board(char **board, int board_size);

/*
**	fillit.c
*/

int		fillit(char **arr_tet, char **board, int board_size, int i);

/*
**	print.c
*/

void	print_board(char **board, int board_size);
void	print_error(void);
#endif
