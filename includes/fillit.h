/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:57:02 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/06 13:23:12 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../src/libft/libft.h"

/*
**	parse_source.c
*/

char	*get_src(char *filename);
t_list	*parse_src(char	*src);
int		check_src(int *tet);

/*
**	fillit.c
*/

char	**fillit(t_list *lst, char **board, int board_size);
int		get_smallest_size(t_list *lst);
char	**make_board(int board_size);

/*
**	print.c
*/

void	print_board(char **board);
void	print_error(void);

#endif
