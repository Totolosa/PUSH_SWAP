/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:31:36 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/27 17:27:34 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_inst(t_lists *list)
{
	int		i;
	long	tmp;

	if (list->na > 1)
	{
		i = -1;
		tmp = list->a[0];
		while (++i < list->na - 1)
			list->a[i] = list->a[i + 1];
		list->a[list->na - 1] = tmp;
		if (list->prog == 'p')
		{
			write(1, "ra", 2);
			if (list->show_stack == 0)
				write(1, "\n", 1);
		}
	}
}

void	rb_inst(t_lists *list)
{
	int		i;
	long	tmp;

	if (list->nb > 1)
	{
		i = -1;
		tmp = list->b[0];
		while (++i < list->nb - 1)
			list->b[i] = list->b[i + 1];
		list->b[list->nb - 1] = tmp;
		if (list->prog == 'p')
		{
			write(1, "rb", 2);
			if (list->show_stack == 0)
				write(1, "\n", 1);
		}
	}
}

void	rr_inst(t_lists *list)
{
	int		i;
	long	tmp;

	if (list->na > 1)
	{
		i = -1;
		tmp = list->a[0];
		while (++i < list->na - 1)
			list->a[i] = list->a[i + 1];
		list->a[list->na - 1] = tmp;
	}
	if (list->nb > 1)
	{
		i = -1;
		tmp = list->b[0];
		while (++i < list->nb - 1)
			list->b[i] = list->b[i + 1];
		list->b[list->nb - 1] = tmp;
	}
	if (list->prog == 'p')
	{
		write(1, "rr", 2);
		if (list->show_stack == 0)
			write(1, "\n", 1);
	}
}
