/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aksuleim <aksuleim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:57:02 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/07 12:39:29 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../src/libft/libft.h"

/*
**	parse_source.c
*/

char	*get_src(char *filename);
int		**parse_src(char	*src);

/*
**	fillit.c
*/

int		fillit(int **arr_tet, char **board, int board_size);
int		get_smallest_size(int **arr_tet);
char	**make_board(int board_size);

/*
**	print.c
*/

void	print_board(char **board, int board_size);
void	print_error(void);

#endif
