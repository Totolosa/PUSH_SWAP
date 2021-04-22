/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:04:35 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/22 19:53:45 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void bloc_of_three(t_lists *list)
{
	if (list->a[0] > list->a[1] && list->a[0] < list->a[2])
		add_one_ins("sa", list);
		// check_if_ss("sa", list);
	else if (list->a[2] > list->a[0] && list->a[2] < list->a[1])
	{
		add_one_ins("pb", list);
		add_one_ins("sa", list);
		// check_if_ss("sa", list);
		add_one_ins("pa", list);
	}
	else if (list->a[0] < list->a[1] && list->a[0] > list->a[2])
	{
		add_one_ins("ra", list);
		// check_if_rr("ra", list);
		add_one_ins("sa", list);
		// check_if_ss("sa", list);
		add_one_ins("rra", list);
		// check_if_rrr("rra", list);
		add_one_ins("sa", list);
		// check_if_ss("sa", list);
	}
	else if (list->a[2] > list->a[1] && list->a[2] < list->a[0])
	{
		add_one_ins("ra", list);
		// check_if_rr("ra", list);
		add_one_ins("pb", list);
		add_one_ins("rra", list);
		// check_if_rrr("rra", list);
		add_one_ins("sa", list);
		// check_if_ss("sa", list);
		add_one_ins("pa", list);
	}
	else if (list->a[1] > list->a[2] && list->a[1] < list->a[0])
	{
		add_one_ins("ra", list);
		// check_if_rr("ra", list);
		add_one_ins("pb", list);
		add_one_ins("rra", list);
		// check_if_rrr("rra", list);
		add_one_ins("sa", list);
		// check_if_ss("sa", list);
		add_one_ins("pa", list);
		add_one_ins("sa", list);
		// check_if_ss("sa", list);
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
	
	// printf("SORT A : to_treat = %d\n", to_treat);
	// print_lists(*list);
	if (to_treat == 2 && list->a[0] > list->a[1])
		add_one_ins("sa", list);
		// check_if_ss("sa", list );
	else if (to_treat == 3)
	{
		if (list->na >= 3)
			bloc_of_three(list);
	}
	else
	{
		if (to_treat % 2 == 0)
			res->mediane = list->ref[(list->nb + to_treat / 2) - 1];
		else
			res->mediane = list->ref[list->nb + to_treat / 2];
		// printf("mediane = %ld\n", res->mediane);
		while (to_treat > 0)
		{
			// printf("list->a[0] = %ld, list->na = %d, list->nb = %d, mediane = %ld\n", list->a[0], list->na, list->nb, res->mediane);
			// if (only_sup(res->mediane, list))
			// {
			// 	add_one_ins("ra", list);
			// 	res->rev_in_a += (to_treat);
			// 	to_treat = 1;
			// }
			// else if (list->a[0] > res->mediane)
			if (list->a[0] > res->mediane)
			{
				add_one_ins("ra", list);
				// check_if_rr("ra", list);
				res->rev_in_a++;
			}
			else if (list->a[0] <= res->mediane)
			{
				add_one_ins("pb", list);
				res->pushed_to_b++;
				if (list->b[0] == res->mediane && !only_sup(res->mediane, list))
					add_one_ins("rb", list);
					// if (check_if_rr("rb", list) == 1)
					// 	res->rev_in_a++;
			}
			to_treat--;
		}
		if (list->b[0] != res->mediane)
			add_one_ins("rrb", list);
			// check_if_rrr("rrb", list);
		// printf("rev_in_a = %d, list->na = %d, mediane = %ld\n", res->rev_in_a, list->na, res->mediane);
		i = -1;
		if (res->rev_in_a < list->na)
			while(++i < res->rev_in_a)// && list->a[list->na - 1] < list->a[0])
				add_one_ins("rra", list);
				// check_if_rrr("rra", list);
								//make && ./push_swap 15 1 0 2 3 4 5 6 7 8 9 10 11 12 13 14
		// if (list->b[0] == res->mediane)
		// 	add_one_ins("pa", list);
	}
}