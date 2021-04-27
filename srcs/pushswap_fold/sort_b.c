/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:15:39 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/27 13:10:54 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	only_less(long mediane, t_lists *list)
{
	int	i;

	if (list->nb == 0)
		return (1);
	i = -1;
	while (++i < list->nb)
		if (list->b[i] >= mediane)
			return (0);
	return (1);
}

static void	basic_sorting_b(int to_treat, t_res *res, t_lists *list)
{
	if (to_treat == 1)
	{
		add_one_ins("pa", list);
		res->pushed_to_a = 1;
	}
	else if (to_treat == 2)
	{
		if (list->b[0] < list->b[1])
			check_if_ss("sb", list);
		add_one_ins("pa", list);
		add_one_ins("pa", list);
		res->pushed_to_a = 2;
	}
	else if (to_treat == 3)
	{
		bloc_of_three_b(list);
		res->pushed_to_a = 3;
	}
}

static void	repartition_values_b(int to_treat, t_res *res, t_lists *list)
{
	int	i;

	i = -1;
	while (++i < to_treat)
	{
		if (only_less(res->mediane, list))
		{
			if (list->b[0] < list->b[1])
				check_if_ss("sb", list);
			i = to_treat;
		}
		else if (list->b[0] < res->mediane)
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
		}
	}
}

void	sort_b(int to_treat, t_res *res, t_lists *list)
{
	int	i;

	if (to_treat == 1 || to_treat == 2 || to_treat == 3)
		basic_sorting_b(to_treat, res, list);
	else if (sorted_list_b(to_treat, list))
	{
		res->pushed_to_a = to_treat;
		while (--to_treat >= 0)
			add_one_ins("pa", list);
	}
	else
	{
		res->mediane = list->ref[(list->nb) - to_treat / 2];
		repartition_values_b(to_treat, res, list);
		if (list->a[0] != res->mediane)
			add_one_ins("rra", list);
		i = -1;
		if (to_treat - res->pushed_to_a < list->nb)
			while (++i < res->rev_in_b)
				add_one_ins("rrb", list);
		res->rev_in_b = to_treat - res->pushed_to_a;
	}
}
