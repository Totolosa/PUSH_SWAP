/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_ok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:51:01 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/27 13:29:36 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	end_do_instruction(int i, t_lists *list)
{
	if (list->ins[i][0] == 'r' && list->ins[i][1] == 'r'
		&& list->ins[i][2] == 'a' && list->ins[i][3] == 0)
		rra_inst(list);
	else if (list->ins[i][0] == 'r' && list->ins[i][1] == 'r'
		&& list->ins[i][2] == 'b' && list->ins[i][3] == 0)
		rrb_inst(list);
	else if (list->ins[i][0] == 'r' && list->ins[i][1] == 'r'
		&& list->ins[i][2] == 'r' && list->ins[i][3] == 0)
		rrr_inst(list);
	if (list->show_stack)
	{
		write(1, list->ins[i], ft_strlen(list->ins[i]));
		print_stack(i, *list);
	}
}

static void	do_instruction(int i, t_lists *l)
{
	if (l->ins[i][0] == 'p' && l->ins[i][1] == 'a' && l->ins[i][2] == 0)
		pa_inst(l);
	else if (l->ins[i][0] == 'p' && l->ins[i][1] == 'b' && l->ins[i][2] == 0)
		pb_inst(l);
	else if (l->ins[i][0] == 's' && l->ins[i][1] == 'a' && l->ins[i][2] == 0)
		sa_inst(l);
	else if (l->ins[i][0] == 's' && l->ins[i][1] == 'b' && l->ins[i][2] == 0)
		sb_inst(l);
	else if (l->ins[i][0] == 's' && l->ins[i][1] == 's' && l->ins[i][2] == 0)
		ss_inst(l);
	else if (l->ins[i][0] == 'r' && l->ins[i][1] == 'a' && l->ins[i][2] == 0)
		ra_inst(l);
	else if (l->ins[i][0] == 'r' && l->ins[i][1] == 'b' && l->ins[i][2] == 0)
		rb_inst(l);
	else if (l->ins[i][0] == 'r' && l->ins[i][1] == 'r' && l->ins[i][2] == 0)
		rr_inst(l);
	end_do_instruction(i, l);
}

static int	check_sorting(t_lists *list)
{
	int	i;

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
	int	i;

	i = -1;
	while (++i < list->n_ins)
		do_instruction(i, list);
	if (check_sorting(list) == 1)
		write(1, "\033[32m\033[1mOK\033[0m\n", 16);
	else
		write(1, "\033[31m\033[1mKO\033[0m\n", 16);
}
