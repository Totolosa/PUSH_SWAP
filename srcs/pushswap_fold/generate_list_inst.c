/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_list_inst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:20:40 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/15 18:24:06 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**add_one_ins(char *new_inst, t_lists *list)
{
	char **new;
	int i;

	new = calloc_lst((list->n_ins + 1) * sizeof(char *), &list->free);
	i = -1;
	while (++i < list->n_ins)
		new[i] = list->ins[i];
	new[i] = ft_strdup_pushswap(new_inst, &list->free);
	list->n_ins++;
	return (new);
}

void	generate_list_inst(t_lists *list)
{
	int i;

	i = -1;
	while (++i < list->nmax - 1)
	{
		if (list->a[i] > list->a[i + 1])
			list->ins = add_one_ins("sa", list);
		list->ins = add_one_ins("pb", list);
	}
	
	// list->ins = add_one_ins("rra", list);
	// list->ins = add_one_ins("pb", list);
	// list->ins = add_one_ins("sa", list);
	// list->ins = add_one_ins("rra", list);
	// list->ins = add_one_ins("pa", list);
}