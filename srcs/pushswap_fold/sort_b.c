/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:15:39 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/21 19:43:20 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void special_three(t_lists *list)
{
	if (list->b[0] < list->b[1] && list->b[0] > list->b[2])
	{
		add_one_ins("sb", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
	}
	else if ((list->b[2] > list->b[1] && list->b[2] < list->b[0]))
	{
		add_one_ins("pa", list);
		add_one_ins("sb", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
	}
}

void sort_b(int to_treat, t_res *res, t_lists *list)
{
	int i;
	
	printf("SORT B : to_treat = %d\n", to_treat);
	print_lists(*list);
	if (to_treat == 1)
		add_one_ins("pa", list);
	else if (sorted_list_b(to_treat, list))
		while (--to_treat >= 0)
			add_one_ins("pa", list);
	else if (to_treat == 2)
	{
		if (list->b[0] < list->b[1])
			add_one_ins("sb", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
	}
	else if (to_treat == 3  && ((list->b[0] < list->b[1] && list->b[0] > list->b[2])
		|| (list->b[2] > list->b[1] && list->b[2] < list->b[0])))
		special_three(list);
	else
	{
		// if (to_treat % 2 == 0)
		// 	mediane = list->ref[(list->nb - 1) - to_treat / 2];
		// else
		res->mediane = list->ref[(list->nb - 1) - to_treat / 2];
		i = -1;
		while (++i < to_treat)
		{
			printf("list->b[0] = %ld, list->na = %d, list->nb = %d, mediane = %ld\n", list->b[0], list->na, list->nb, res->mediane);
			if (list->b[0] < res->mediane) // && !only_less(res->mediane, list))
			{
				add_one_ins("rb", list);
				res->rev_in_b++;
			}
			else 
			{
				add_one_ins("pa", list);
				res->pushed_to_a++;
				if (list->a[0] == res->mediane && i != to_treat - 1)
					add_one_ins("ra", list);
			}
		}
		if (list->a[0] != res->mediane)
			add_one_ins("rra", list);
		i = -1;
		if (res->rev_in_b < list->nb)
			while(++i < res->rev_in_b)
				add_one_ins("rrb", list);
		printf("rev_in_b = %d\n", res->rev_in_b);
		// i = -1;
		// while (++i < res->rev_in_b)
		// 	add_one_ins("pa", list);
	}
}