/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:35:55 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/15 16:54:39 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_max(int *max, t_lists list)
{
	if (list.na >= list.nb)
		*max = list.na;
	else 
		*max = list.nb;
}

void	print_lists(t_lists list)
{
	int i;
	int j;
	int k;
	int max;

	init_max(&max, list);
	i = -1;
	j = 0;
	k = 0;
	while (++i < max)
	{
		if (i >= max - list.na)
			ft_putnbr_fd_pushswap(list.a[j++], STDOUT_FILENO);
		else
			write(1, " ", 1);
		write(1, " ", 1);
		if (i >= max - list.nb)
			ft_putnbr_fd_pushswap(list.b[k++], STDOUT_FILENO);
		else
			write(1, " ", 1);
		write(1, "\n", 1);
	}
	write(1, "- -\na b\n", 8);
}
