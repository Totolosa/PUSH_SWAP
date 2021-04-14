/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:31:36 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/14 17:43:23 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa_inst(t_lists *list)
{
	int i;

	if (list->nb > 0)
	{
		if (list->na > 0)
		{
			i = list->na + 1;
			while (--i > 0)
				list->a[i] = list->a[i - 1];
		}
		list->a[0] = list->b[0];
		i = -1;
		while (++i < list->nb - 1)
			list->b[i] = list->b[i + 1];
		list->b[i] = NAN;
		list->na++;
		list->nb--;
	}
}

void pb_inst(t_lists *list)
{
	int i;

	if (list->na > 0)
	{
		if (list->nb > 0)
		{
			i = list->nb + 1;
			while (--i > 0)
				list->b[i] = list->b[i - 1];
		}
		list->b[0] = list->a[0];
		i = -1;
		while (++i < list->na - 1)
			list->a[i] = list->a[i + 1];
		list->a[i] = NAN;
		list->nb++;
		list->na--;
	}
}
