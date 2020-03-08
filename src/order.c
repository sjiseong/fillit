/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:35:38 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/07 18:21:56 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_in_order(int i, int *order)
{
	int	j;

	j = 0;
	while (order[j] != -1)
	{
		if (i == order[j])
			return (1);
		j++;
	}
	return (0);
}

void	add_in_order(int i, int *order)
{
	int	j;

	j = 0;
	while (order[j] != -1)
		j++;
	order[j] = i;
}

void	revert_order(int i, int *order)
{
	int	j;

	j = 0;
	while (order[j] != i)
		j++;
	while (order[j] != -1)
		order[j++] = -1;
}

int		get_order_len(int *order)
{
	int	i;

	i = 0;
	while (order[i] != -1)
		i++;
	return (i);
}
