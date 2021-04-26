/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:04:35 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/26 16:05:16 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	only_sup(long mediane, t_lists *list)
{
	int	i;

	i = -1;
	while (++i < list->na)
		if (list->a[i] <= mediane)
			return (0);
	return (1);
}

static void	repartition_values_a(int to_treat, t_res *res, t_lists *list)
{
	int	i;

	i = -1;
	while (++i < to_treat)
	{
		if (only_sup(res->mediane, list))
		{
			if (list->a[0] > list->a[1])
				check_if_ss("sa", list);
			i = to_treat;
		}
		else if (list->a[0] > res->mediane)
		{
			add_one_ins("ra", list);
			res->rev_in_a++;
		}
		else if (list->a[0] <= res->mediane)
		{
			add_one_ins("pb", list);
			res->pushed_to_b++;
			if (list->b[0] == res->mediane && list->nb > 1
				&& !only_sup(res->mediane, list))
				add_one_ins("rb", list);
		}
	}
}

void	sort_a(int to_treat, t_res *res, t_lists *list)
{
	int	i;

	if (to_treat == 2 && list->a[0] > list->a[1])
		check_if_ss("sa", list);
	else if (to_treat == 3)
		bloc_of_three_a(list);
	else
	{
		if (to_treat % 2 == 0)
			res->mediane = list->ref[(list->nb + to_treat / 2) - 1];
		else
			res->mediane = list->ref[list->nb + to_treat / 2];
		repartition_values_a(to_treat, res, list);
		if (list->b[0] != res->mediane)
			add_one_ins("rrb", list);
		i = -1;
		if (to_treat - res->pushed_to_b < list->na)
			while (++i < res->rev_in_a)
				add_one_ins("rra", list);
	}
	res->rev_in_a = to_treat - res->pushed_to_b;
}
