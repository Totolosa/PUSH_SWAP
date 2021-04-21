/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:35:55 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/21 18:00:57 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	init_max(int *max, t_lists list)
// {
// 	if (list.na >= list.nb)
// 		*max = list.na;
// 	else 
// 		*max = list.nb;
// }

void	print_lists(t_lists list)
{
	int i;

	write(1, "LISTS : ", 8);
	if (list.nb > 0)
	{
		i = list.nb - 1;
		while (i >= 0)
		{
			ft_putnbr_fd(list.b[i--], 1);
			write(1, " ", 1);
		}
	}
	write(1, "|| ", 3);
	if (list.na > 0)
	{
		i = -1;
		while (++i < list.na)
		{
			ft_putnbr_fd(list.a[i], 1);
			if (i != list.na - 1)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}

	// init_max(&max, list);
	// i = -1;
	// j = 0;
	// k = 0;
	// printf("LISTS : \n");
	// while (++i < max)
	// {
	// 	if (i >= max - list.na)
	// 		ft_putnbr_fd_pushswap(list.a[j++], STDOUT_FILENO);
	// 	else
	// 		write(1, " ", 1);
	// 	write(1, " ", 1);
	// 	if (i >= max - list.nb)
	// 		ft_putnbr_fd_pushswap(list.b[k++], STDOUT_FILENO);
	// 	else
	// 		write(1, " ", 1);
	// 	write(1, "\n", 1);
	// }
	// write(1, "- -\na b\n", 8);
}
