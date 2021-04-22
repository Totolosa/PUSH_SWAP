/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_ins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:33:20 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/22 17:16:42 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_if_ss(char *sx, t_lists *list)
{
	if (list->na > 1 && list->nb > 1 && list->a[0] > list->a[1] && list->b[0] < list->b[1])
		add_one_ins("ss", list);
	else
	{
		if (sx[1] == 'a')
			add_one_ins("sa", list);
		else if (sx[1] == 'b')
			add_one_ins("sb", list);
	}
}

int check_if_rr(char *rx, t_lists *list)
{
	long mediane;
	
	if (rx[1] == 'a')
	{
		mediane = list->ref[(list->nb - 1) / 2];
		if (list->b[0] <= mediane)
		{
			add_one_ins("rr", list);
			return (1);
		}
		else
			add_one_ins("ra", list);
	}
	else if (rx[1] == 'b')
	{
		if (list->na % 2 == 0)
			mediane = list->ref[(list->nb + list->na / 2) - 1];
		else
			mediane = list->ref[list->nb + list->na / 2];
		if (list->a[0] >= mediane)
		{
			add_one_ins("rr", list);
			return (1);
		}
		else
			add_one_ins("rb", list);
	}
	return (0);
}

int check_if_rrr(char *rrx, t_lists *list)
{
	long mediane;
	
	if (rrx[2] == 'a')
	{
		mediane = list->ref[(list->nb - 1) / 2];
		if (list->nb > 1 && list->b[list->nb - 1] > mediane)
		{
			add_one_ins("rrr", list);
			return (1);
		}
		else
			add_one_ins("rra", list);
	}
	else if (rrx[2] == 'b')
	{
		if (list->na % 2 == 0)
			mediane = list->ref[(list->nb + list->na / 2) - 1];
		else
			mediane = list->ref[list->nb + list->na / 2];
		if (list->na > 1 && list->a[list->na - 1] < mediane)
		{
			add_one_ins("rrr", list);
			return (1);
		}
		else
			add_one_ins("rrb", list);
	}
	return (0);
}