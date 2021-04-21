/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_list_inst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:20:40 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/21 19:14:04 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_ref(t_lists *list)
{
	int i;
	int j;
	long tmp;

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
	printf("ref :\n");
	i = -1;
	while (++i < list->nmax)
		printf("%ld ", list->ref[i]);
	printf("\n");
}

void sort_all(int to_treat, t_lists *list)
{
	t_res res;
	
	ft_bzero(&res, sizeof(t_res));
	if (to_treat > 1)
	{
		sort_a(to_treat, &res, list);
		print_instructions(*list);
	}
	if (!sorted_list_a(list))
		sort_all(list->na, list);
	sort_all2(res.pushed_to_b, list);
}
	
void sort_all2(int to_treat, t_lists *list)
{
	t_res res_b;
	
	ft_bzero(&res_b, sizeof(t_res));
	if (to_treat > 0)
	{
		sort_b(to_treat, &res_b, list);
		print_instructions(*list);
	}
	if (!sorted_list_a(list))
		sort_all(res_b.pushed_to_a, list);
	// if (!sorted_list_b(res_b.rev_in_b, list))
	if (res_b.rev_in_b > 0)
		sort_all2(res_b.rev_in_b, list);
	
	// if (!sorted_list_b(res.rev_in_b, list))
	// 	sort_b(res.rev_in_b, &res, list);
	// if (!sorted_list_a(list))
	// 	sort_all(res.pushed_to_a, list);
}

void	generate_list_inst(t_lists *list)
{
	sort_ref(list);
	if (!sorted_list_a(list))
		sort_all(list->nmax, list);
	// if (sorted_list_a(list) && list->nb > 0 && sorted_list_b(list->nb, list))
	// 	while (list->nb > 0)
	// 		add_one_ins("pa", list);
	print_lists(*list);
}