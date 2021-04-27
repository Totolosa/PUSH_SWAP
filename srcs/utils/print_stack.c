/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:35:55 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/27 13:07:55 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(int indice, t_lists list)
{
	int	i;

	if (list.ins[indice][2] != '\0')
		write(1, "  \033[36m-->\033[0m   ", 16);
	else
		write(1, "   \033[36m-->\033[0m   ", 17);
	if (list.nb > 0)
	{
		i = list.nb - 1;
		while (i >= 0)
			ft_putnbr_fd_pushswap(list.b[i--], 1);
	}
	write(1, "\033[33m||\033[0m ", 12);
	if (list.na > 0)
	{
		i = -1;
		while (++i < list.na)
			ft_putnbr_fd_pushswap(list.a[i], 1);
		write(1, "\n", 1);
	}
}
