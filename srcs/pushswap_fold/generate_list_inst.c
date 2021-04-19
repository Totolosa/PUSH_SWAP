/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_list_inst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:20:40 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/19 19:38:22 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_instruction(char *str, t_lists *l)
{
	if (str[0] == 'p' && str[1] == 'a')
		pa_inst(l);
	else if (str[0] == 'p' && str[1] == 'b')
		pb_inst(l);
	else if (str[0] == 's' && str[1] == 'a')
		sa_inst(l);
	else if (str[0] == 's' && str[1] == 'b')
		sb_inst(l);
	else if (str[0] == 's' && str[1] == 's')
		ss_inst(l);
	else if (str[0] == 'r' && str[1] == 'a')
		ra_inst(l);
	else if (str[0] == 'r' && str[1] == 'b')
		rb_inst(l);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 0)
		rr_inst(l);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		rra_inst(l);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		rrb_inst(l);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		rrr_inst(l);
}

static void	add_one_ins(char *new_inst, t_lists *list)
{
	char **new;
	int i;

	new = calloc_lst((list->n_ins + 1) * sizeof(char *), &list->free);
	i = -1;
	while (++i < list->n_ins)
		new[i] = list->ins[i];
	new[i] = ft_strdup_pushswap(new_inst, &list->free);
	list->n_ins++;
	list->ins = new;
	do_instruction(new_inst, list);
}

// static void	place_mediane_pivot_a(long *pivot, t_lists *list)
// {
// 	if ((list->a[0] > list->a[1] && list->a[0] < list->a[list->na - 1])
// 		|| (list->a[0] < list->a[1] && list->a[0] > list->a[list->na - 1]))
// 	{
// 		add_one_ins("ra", list);
// 	}
// 	else if ((list->a[0] < list->a[1] && list->a[1] < list->a[list->na - 1])
// 		|| (list->a[0] > list->a[1] && list->a[1] > list->a[list->na - 1]))
// 	{
// 		add_one_ins("sa", list);
// 		add_one_ins("ra", list);
// 	}
// 	*pivot = list->a[list->na - 1];
// }

// static void	place_mediane_pivot_b(long *pivot, t_lists *list)
// {
// 	if ((list->b[0] > list->b[1] && list->b[0] < list->b[list->nb - 1])
// 		|| (list->b[0] < list->b[1] && list->b[0] > list->b[list->nb - 1]))
// 	{
// 		add_one_ins("rb", list);
// 	}
// 	else if ((list->b[0] < list->b[1] && list->b[1] < list->b[list->nb - 1])
// 		|| (list->b[0] > list->b[1] && list->b[1] > list->b[list->nb - 1]))
// 	{
// 		add_one_ins("sb", list);
// 		add_one_ins("rb", list);
// 	}
// 	*pivot = list->b[list->nb - 1];
// }

int sorted_list_a(long *list, int size)
{
	int i;

	i = -1;
	while (++i < size - 1)
		if (list[i] > list[i + 1])
			return (0);
	return (1);
}

int sorted_list_b(long *list, int size)
{
	int i;

	i = -1;
	while (++i < size - 1)
		if (list[i] < list[i + 1])
			return (0);
	return (1);
}

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

void init_sorting(t_lists *list)
{
	long mediane;
	int i;
	
//	place_mediane_pivot_a(&pivot, list);
	mediane = list->ref[(list->nmax / 2) - 1];
	printf("mediane = %ld, list->nmax = %d, \n", mediane, list->nmax);
	i = -1;
	while (++i < list->nmax)
	{
		if (list->a[0] > mediane )
			add_one_ins("ra", list);
		else if (list->a[0] < mediane)
			add_one_ins("pb", list);
		else if (list->a[0] == mediane )
		{
			add_one_ins("pb", list);
			add_one_ins("rb", list);
		}
	}
	printf("\nLists :\n");
	print_lists(*list);
	if (list->nb > 1 && list->na > 1 && list->b[0] < list->b[1] && list->a[0] > list->a[1])
		add_one_ins("ss", list);
	else if (list->nb > 1 && list->b[0] < list->b[1])
		add_one_ins("sb", list);
	else if (list->na > 1 && list->a[0] > list->a[1])
		add_one_ins("sa", list);
	add_one_ins("rrb", list);
	printf("\nLists :\n");
	print_lists(*list);
}

void sort_b(t_lists *list)
{
	long mediane;
	int to_treat;
	int pushed_to_a;
	int i;
	
	pushed_to_a = 0;
	to_treat = list->nb;
	if (list->nb % 2 == 0)
		mediane = list->ref[(list->nb / 2) - 1];
	else
		mediane = list->ref[list->nb / 2];
	i = -1;
	while (++i < to_treat)
	{
		printf("list->nb = %d, mediane = %ld\n", list->nb, mediane);
		if (list->b[0] < mediane)
			add_one_ins("rb", list);
		else 
		{
			pushed_to_a++;
			add_one_ins("pa", list);
			if (list->a[0] == mediane )
				add_one_ins("ra", list);
		}
	}
	add_one_ins("rra", list);
	printf("pushed_to_a = %d\n", pushed_to_a);
	if (!sorted_list_b(list->b, list->nb))
		sort_b(list);
	
}

void	generate_list_inst(t_lists *list)
{
	
//	long pivot;

	sort_ref(list);
	init_sorting(list);
	sort_b(list);
	print_lists(*list);
}