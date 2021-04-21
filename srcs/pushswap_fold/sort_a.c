/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:04:35 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/21 18:01:44 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void bloc_of_three(t_lists *list)
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
		add_one_ins("sb", list);
		add_one_ins("rra", list);
		add_one_ins("sb", list);
	}
	else if (list->a[2] > list->a[1] && list->a[2] < list->a[0])
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

static int only_sup(long mediane, t_lists *list)
{
	int i;
	
	i = -1;
	while (++i < list->na)
		if (list->a[i] <= mediane)
			return (0);
	return (1);
}

void	sort_a(int to_treat, t_res *res, t_lists *list)
{
	int i;
	
	print_lists(*list);
	printf("SORT A : to_treat = %d\n", to_treat);
	if (to_treat == 2 && list->a[0] > list->a[1])
		add_one_ins("sa", list);
	else if (to_treat == 3)
	{
		if (list->nb >= 3)
			bloc_of_three(list);
	}
	else
	{
		if (to_treat % 2 == 0)
			res->mediane = list->ref[(list->nb - 1 ) + to_treat / 2];
		else
			res->mediane = list->ref[list->nb + to_treat / 2];
		i = -1;
		while (++i < to_treat)
		{
			printf("list->a[0] = %ld, list->na = %d, list->nb = %d, mediane = %ld\n", list->a[0], list->na, list->nb, res->mediane);
			if (list->a[0] > res->mediane && !only_sup(res->mediane, list))
			{
				add_one_ins("ra", list);
				res->rev_in_a++;
			}
			else if (list->a[0] < res->mediane || list->a[0] == res->mediane)
			{
				add_one_ins("pb", list);
				res->pushed_to_b++;
				if (list->b[0] == res->mediane && !only_sup(res->mediane, list))
					add_one_ins("rb", list);
			}
		}
		if (list->b[0] != res->mediane)
			add_one_ins("rrb", list);
	}
}