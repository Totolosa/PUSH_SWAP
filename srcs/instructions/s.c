/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:31:36 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/22 12:32:33 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa_inst(t_lists *list)
{
	long tmp;

	if (list->na > 1)
	{
		tmp = list->a[0];
		list->a[0] = list->a[1];
		list->a[1] = tmp;
	}
}

void sb_inst(t_lists *list)
{
	long tmp;

	if (list->nb > 1)
	{
		tmp = list->b[0];
		list->b[0] = list->b[1];
		list->b[1] = tmp;
	}
}

void ss_inst(t_lists *list)
{
	sa_inst(list);
	sb_inst(list);
}