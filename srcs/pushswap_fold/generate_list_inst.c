/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_list_inst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:20:40 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/15 18:04:53 by tdayde           ###   ########lyon.fr   */
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
	(void)list;
	
	list->ins = add_one_ins("rra", list);
	list->ins = add_one_ins("pb", list);
	list->ins = add_one_ins("sa", list);
	list->ins = add_one_ins("rra", list);
	list->ins = add_one_ins("pa", list);
//	write(1, "rra\npb\nsa\nrra\npa\n", 17);
}