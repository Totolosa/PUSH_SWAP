/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:31:36 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/14 19:09:05 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra_inst(t_lists *list)
{
	int i;
	long tmp;

	if (list->na > 1)
	{
		i = 0;
		tmp = list->a[0];
		while (i < list->na - 1)
		{
			list->a[i] = list->a[i + 1];
			i++;
		}
		list->a[list->na - 1] = tmp;
	}
}

void rb_inst(t_lists *list)
{
	int i;
	long tmp;

	if (list->nb > 1)
	{
		i = 0;
		tmp = list->b[0];
		while (i < list->nb - 1)
		{
			list->b[i] = list->b[i + 1];
			i++;
		}
		list->b[list->nb - 1] = tmp;
	}
}

void rr_inst(t_lists *list)
{
	ra_inst(list);
	rb_inst(list);
}

