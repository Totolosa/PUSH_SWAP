/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:29:17 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/21 12:30:12 by tdayde           ###   ########lyon.fr   */
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

void	add_one_ins(char *new_inst, t_lists *list)
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

int sorted_list_a(t_lists *list)
{
	int i;

	i = -1;
	while (++i < list->na - 1)
		if (list->a[i] > list->a[i + 1])
			return (0);
	return (1);
}

int sorted_list_b(int interval, t_lists *list)
{
	int i;

	i = -1;
	while (++i < interval - 1)
		if (list->b[i] < list->b[i + 1])
			return (0);
	return (1);
}