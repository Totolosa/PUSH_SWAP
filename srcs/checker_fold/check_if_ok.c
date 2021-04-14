/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_ok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:51:01 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/14 19:09:51 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_instruction(int i, t_lists *l)
{
	if (l->ins[i][0] == 'p' && l->ins[i][1] == 'a')
		pa_inst(l);
	else if (l->ins[i][0] == 'p' && l->ins[i][1] == 'b')
		pb_inst(l);
	else if (l->ins[i][0] == 's' && l->ins[i][1] == 'a')
		sa_inst(l);
	else if (l->ins[i][0] == 's' && l->ins[i][1] == 'b')
		sb_inst(l);
	else if (l->ins[i][0] == 's' && l->ins[i][1] == 's')
		ss_inst(l);
	else if (l->ins[i][0] == 'r' && l->ins[i][1] == 'a')
		ra_inst(l);
	else if (l->ins[i][0] == 'r' && l->ins[i][1] == 'b')
		rb_inst(l);
	else if (l->ins[i][0] == 'r' && l->ins[i][1] == 'r' && l->ins[i][2] == 0)
		rr_inst(l);
	else if (l->ins[i][0] == 'r' && l->ins[i][1] == 'r' && l->ins[i][2] == 'a')
		rra_inst(l);
	else if (l->ins[i][0] == 'r' && l->ins[i][1] == 'r' && l->ins[i][2] == 'b')
		rrb_inst(l);
	else if (l->ins[i][0] == 'r' && l->ins[i][1] == 'r' && l->ins[i][2] == 'r')
		rrr_inst(l);
}

static int	check_sorting(t_lists *list)
{
	int i;
	
	i = -1;
	while (++i < list->nmax)
		if (list->b[i] != NAN)
			return (0);
	i = -1;
	while (++i < list->nmax - 1)
		if (list->a[i] >= list->a[i + 1])
			return (0);
	return (1);
}

void	check_if_ok(t_lists *list)
{
	int i;

	i = -1;
	while (++i < list->n_ins)
		do_instruction(i, list);
	if (check_sorting(list) == 1)
		write(1, "OK\n", 3);
	else 
		write(1, "KO\n", 3);
}