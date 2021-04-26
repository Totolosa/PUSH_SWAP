/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pack_of_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:33:20 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/26 17:23:21 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	end_bloc_of_three_a(t_lists *list)
{
	if (list->a[2] > list->a[1] && list->a[2] < list->a[0])
	{
		add_one_ins("ra", list);
		add_one_ins("pb", list);
		add_one_ins("rra", list);
		add_one_ins("sa", list);
		add_one_ins("pa", list);
	}
	else if (list->a[1] > list->a[2] && list->a[1] < list->a[0])
	{
		add_one_ins("ra", list);
		add_one_ins("pb", list);
		add_one_ins("rra", list);
		add_one_ins("sa", list);
		add_one_ins("pa", list);
		add_one_ins("sa", list);
	}
}

void	bloc_of_three_a(t_lists *list)
{
	if (list->a[0] > list->a[1] && list->a[0] < list->a[2])
		add_one_ins("sa", list);
	else if (list->a[2] > list->a[0] && list->a[2] < list->a[1])
	{
		add_one_ins("pb", list);
		add_one_ins("sa", list);
		add_one_ins("pa", list);
	}
	else if (list->a[0] < list->a[1] && list->a[0] > list->a[2])
	{
		add_one_ins("ra", list);
		add_one_ins("sa", list);
		add_one_ins("rra", list);
		add_one_ins("sa", list);
	}
	else
		end_bloc_of_three_a(list);
}

static void	end_bloc_of_three_b(t_lists *list)
{
	if ((list->b[2] > list->b[1] && list->b[2] < list->b[0]))
	{
		add_one_ins("pa", list);
		check_if_ss("sb", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
	}
	else if ((list->b[0] > list->b[1] && list->b[0] < list->b[2]))
	{
		add_one_ins("rb", list);
		check_if_ss("sb", list);
		add_one_ins("pa", list);
		add_one_ins("rrb", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
	}
	else if ((list->b[1] > list->b[0] && list->b[1] < list->b[2]))
	{
		add_one_ins("rb", list);
		check_if_ss("sb", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
		add_one_ins("rrb", list);
		add_one_ins("pa", list);
	}
}

void	bloc_of_three_b(t_lists *list)
{
	if ((list->b[2] > list->b[0] && list->b[2] < list->b[1]))
	{
		add_one_ins("rb", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
		add_one_ins("rrb", list);
		add_one_ins("pa", list);
	}
	else if ((list->b[1] > list->b[2] && list->b[1] < list->b[0]))
	{
		add_one_ins("pa", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
	}
	else if (list->b[0] > list->b[2] && list->b[0] < list->b[1])
	{
		check_if_ss("sb", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
	}
	else
		end_bloc_of_three_b(list);
}

void	special_sort(t_lists *list)
{
	add_one_ins("sa", list);
	add_one_ins("ra", list);
	add_one_ins("pb", list);
	add_one_ins("pb", list);
	add_one_ins("sa", list);
	add_one_ins("pa", list);
	add_one_ins("pa", list);
}
