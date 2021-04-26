/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:31:36 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/26 17:54:56 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_inst(t_lists *list)
{
	long	tmp;

	if (list->na > 1)
	{
		tmp = list->a[0];
		list->a[0] = list->a[1];
		list->a[1] = tmp;
		if (list->prog == 'p')
		{
			write(1, "sa", 2);
			if (list->show_stack == 0)
				write(1, "\n", 1);
		}
	}
}

void	sb_inst(t_lists *list)
{
	long	tmp;

	if (list->nb > 1)
	{
		tmp = list->b[0];
		list->b[0] = list->b[1];
		list->b[1] = tmp;
		if (list->prog == 'p')
		{
			write(1, "sb", 2);
			if (list->show_stack == 0)
				write(1, "\n", 1);
		}
	}
}

void	ss_inst(t_lists *list)
{
	long	tmp;

	if (list->na > 1)
	{
		tmp = list->a[0];
		list->a[0] = list->a[1];
		list->a[1] = tmp;
	}
	if (list->nb > 1)
	{
		tmp = list->b[0];
		list->b[0] = list->b[1];
		list->b[1] = tmp;
	}
	if (list->prog == 'p')
	{
		write(1, "ss", 2);
		if (list->show_stack == 0)
			write(1, "\n", 1);
	}
}
