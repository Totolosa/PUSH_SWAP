/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:31:36 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/27 12:40:44 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_inst(t_lists *list)
{
	int		i;
	long	tmp;

	if (list->na > 1)
	{
		i = list->na - 1;
		tmp = list->a[i];
		while (i > 0)
		{
			list->a[i] = list->a[i - 1];
			i--;
		}
		list->a[0] = tmp;
		if (list->prog == 'p')
		{
			write(1, "rra", 3);
			if (list->show_stack == 0)
				write(1, "\n", 1);
		}
	}
}

void	rrb_inst(t_lists *list)
{
	int		i;
	long	tmp;

	if (list->nb > 1)
	{
		i = list->nb - 1;
		tmp = list->b[i];
		while (i > 0)
		{
			list->b[i] = list->b[i - 1];
			i--;
		}
		list->b[0] = tmp;
		if (list->prog == 'p')
		{
			write(1, "rrb", 3);
			if (list->show_stack == 0)
				write(1, "\n", 1);
		}
	}
}

void	rrr_inst(t_lists *list)
{
	rra_inst(list);
	rrb_inst(list);
	write(1, "rrr", 3);
	if (list->show_stack == 0)
		write(1, "\n", 1);
}
