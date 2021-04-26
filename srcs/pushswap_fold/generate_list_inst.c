/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_list_inst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:20:40 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/26 16:46:45 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	list_of_three(long a, long b, long c, t_lists *list)
{
	if (c > b && c < a)
		add_one_ins("ra", list);
	else if (a > b && a < c)
		add_one_ins("sa", list);
	else if (a > c && a < b)
		add_one_ins("rra", list);
	else if (b > c && b < a)
	{
		add_one_ins("ra", list);
		add_one_ins("sa", list);
	}
	else if (c > a && c < b)
	{
		add_one_ins("rra", list);
		add_one_ins("sa", list);
	}
}

void	sort_ref(t_lists *list)
{
	int		i;
	int		j;
	long	tmp;

	list->ref = calloc_lst(sizeof(long) * list->nmax, &list->free);
	if (list->ref == NULL)
		fail(list);
	i = -1;
	while (++i < list->nmax)
		list->ref[i] = list->a[i];
	i = -1;
	while (++i < list->nmax - 1)
	{
		j = -1;
		while (++j < list->nmax - 1 - i)
		{
			if (list->ref[j] > list->ref[j + 1])
			{
				tmp = list->ref[j];
				list->ref[j] = list->ref[j + 1];
				list->ref[j + 1] = tmp;
			}
		}
	}
}

void	sort_all(int to_treat, t_lists *list)
{
	t_res	res;

	ft_bzero(&res, sizeof(t_res));
	if (to_treat > 1)
	{
		if (list->show_repartition)
			copy_lists_before_repartition(list);
		sort_a(to_treat, &res, list);
		if (list->show_repartition)
			print_repartition_a(to_treat, res, *list);
	}
	if (!sorted_list_a(list))
		sort_all(res.rev_in_a, list);
	sort_all2(res.pushed_to_b, list);
}

void	sort_all2(int to_treat, t_lists *list)
{
	t_res	res_b;

	ft_bzero(&res_b, sizeof(t_res));
	if (to_treat > 0)
	{
		if (list->show_repartition)
			copy_lists_before_repartition(list);
		sort_b(to_treat, &res_b, list);
		if (list->show_repartition)
			print_repartition_b(to_treat, res_b, *list);
	}
	if (!sorted_list_a(list))
		sort_all(res_b.pushed_to_a, list);
	if (res_b.rev_in_b > 0)
		sort_all2(res_b.rev_in_b, list);
}

void	generate_list_inst(t_lists *list)
{
	if (!sorted_list_a(list))
	{
		sort_ref(list);
		if (list->na == 2)
			add_one_ins("sa", list);
		else if (list->na == 3)
			list_of_three(list->a[0], list->a[1], list->a[2], list);
		else if (list->na == 5 && list->a[0] == 1 && list->a[1] == 5
			&& list->a[2] == 2 && list->a[3] == 4 && list->a[4] == 3)
			special_sort(list);
		else
			sort_all(list->nmax, list);
	}
	else
		return ;
}
