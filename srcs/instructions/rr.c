/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:31:36 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/14 19:06:13 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra_inst(t_lists *list)
{
	int i;
	long tmp;

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
	}
}

void rrb_inst(t_lists *list)
{
	int i;
	long tmp;

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
	}
}

void rrr_inst(t_lists *list)
{
	rra_inst(list);
	rrb_inst(list);
}
