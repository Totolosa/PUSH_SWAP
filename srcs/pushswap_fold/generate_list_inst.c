/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_list_inst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:20:40 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/16 18:09:25 by tdayde           ###   ########lyon.fr   */
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

static void	place_mediane_pivot_a(long *pivot, t_lists *list)
{
	if ((list->a[0] > list->a[1] && list->a[0] < list->a[list->na - 1])
		|| (list->a[0] < list->a[1] && list->a[0] > list->a[list->na - 1]))
	{
		add_one_ins("ra", list);
	}
	else if ((list->a[0] < list->a[1] && list->a[1] < list->a[list->na - 1])
		|| (list->a[0] > list->a[1] && list->a[1] > list->a[list->na - 1]))
	{
		add_one_ins("sa", list);
		add_one_ins("ra", list);
	}
	*pivot = list->a[list->na - 1];
}

int sorted_list(long *list, int size)
{
	int i;

	i = -1;
	while (++i < size - 1)
		if (list[i] > list[i + 1])
			return (0);
	return (1);
}

void init_sorting(t_lists *list)
{
	long pivot;
	
	place_mediane_pivot_a(&pivot, list);
	while (list->a[0] != pivot)
	{
		if (list->a[0] < pivot)
			add_one_ins("pb", list);
		else 
			add_one_ins("ra", list);
	}
	if (list->nb > 1 && list->b[0] < list->b[1])
		add_one_ins("sb", list);
	printf("\nLists :\n");
	print_lists(*list);
}

void	generate_list_inst(t_lists *list)
{
//	int i;

	init_sorting(list);
//	printf("TEST\n");
	// while (!sorted_list(list->a, list->na) && list->b[0] != NAN)
	// {

	// }
	
	// i = -1;
	// while (++i < list->nmax - 1)
	// {
	// 	if (list->a[i] > list->a[i + 1])
	// 		list->ins = add_one_ins("sa", list);
	// 	list->ins = add_one_ins("pb", list);
	// }
	
	// list->ins = add_one_ins("rra", list);
	// list->ins = add_one_ins("pb", list);
	// list->ins = add_one_ins("sa", list);
	// list->ins = add_one_ins("rra", list);
	// list->ins = add_one_ins("pa", list);
}