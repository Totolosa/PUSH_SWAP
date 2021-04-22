/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:15:39 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/22 19:51:10 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void special_three(t_lists *list)
{
	if ((list->b[1] > list->b[2] && list->b[1] < list->b[0]))
	{
		add_one_ins("pa", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
	}
	else if (list->b[0] > list->b[2] && list->b[0] < list->b[1])
	{
		add_one_ins("sb", list);
		// check_if_ss("sb", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
	}
	else if ((list->b[2] > list->b[1] && list->b[2] < list->b[0]))
	{
		add_one_ins("pa", list);
		add_one_ins("sb", list);
		// check_if_ss("sb", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
	}
	else if ((list->b[2] > list->b[0] && list->b[2] < list->b[1]))
	{
		add_one_ins("rb", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
		add_one_ins("rrb", list);
		add_one_ins("pa", list);
	}
	else if ((list->b[0] > list->b[1] && list->b[0] < list->b[2]))
	{
		add_one_ins("rb", list);
		add_one_ins("sb", list);
		add_one_ins("pa", list);
		add_one_ins("rrb", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
	}
	else if ((list->b[1] > list->b[0] && list->b[1] < list->b[2]))
	{
		add_one_ins("rb", list);
		add_one_ins("sb", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
		add_one_ins("rrb", list);
		add_one_ins("pa", list);
	}
}

static int only_less(long mediane, t_lists *list)
{
	int i;
	
	if (list->nb == 0)
		return (1);
	i = -1;
	while (++i < list->nb)
		if (list->b[i] >= mediane)
			return (0);
	return (1);
}

void sort_b(int to_treat, t_res *res, t_lists *list)
{
	int i;
	
	// printf("SORT B : to_treat = %d\n", to_treat);
	// print_lists(*list);
	if (to_treat == 1)
		add_one_ins("pa", list);
	else if (to_treat == 2)
	{
		if (list->b[0] < list->b[1])
			add_one_ins("sb", list);
			// check_if_ss("sb", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
	}
	else if (to_treat == 3)
		special_three(list);
	else if (sorted_list_b(to_treat, list))
		while (--to_treat >= 0)
			add_one_ins("pa", list);
	else
	{
		// if (to_treat % 2 == 0)
		// 	mediane = list->ref[(list->nb - 1) - to_treat / 2];
		// else
		res->mediane = list->ref[(list->nb) - to_treat / 2];
		// printf("mediane = %ld\n", res->mediane);
		i = -1;
		while (++i < to_treat)
		{
			// printf("list->b[0] = %ld, list->na = %d, list->nb = %d, mediane = %ld\n", list->b[0], list->na, list->nb, res->mediane);
			if (list->b[0] < res->mediane)// && !only_less(res->mediane, list))
			{
				add_one_ins("rb", list);
				res->rev_in_b++;
			}
			else if (list->b[0] >= res->mediane)
			{
				add_one_ins("pa", list);
				res->pushed_to_a++;
				if (list->a[0] == res->mediane && !only_less(res->mediane, list))
					add_one_ins("ra", list);
					// if (check_if_rr("ra", list) == 1)
					// 	res->rev_in_b++;
			}
		}
		if (list->a[0] != res->mediane)
			add_one_ins("rra", list);
			// check_if_rrr("rra", list);
		i = -1;
		if (res->rev_in_b < list->nb)
			while(++i < res->rev_in_b) // && list->b[list->nb - 1] > list->b[0])
				add_one_ins("rrb", list);
		// i = -1;
		// while (++i < res->rev_in_b)
		// 	add_one_ins("pa", list);
	}
}