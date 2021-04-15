/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:44:54 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/15 15:45:34 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void isaint(t_lists *list, int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				fail(list);
	}
}

void create_lists(t_lists *list, int argc, char **argv)
{
	int i;
	
	list->nmax = argc -1;
	list->na = argc - 1;
	list->nb = 0;
	list->a = calloc_lst(sizeof(long *) * (argc - 1), &list->free);
	if (list->a == NULL)
		fail(list);
	i = 0;
	while (++i < argc)
		list->a[i - 1] = ft_atoi_pushswap(argv[i]);
	list->b = calloc_lst(sizeof(long *) * (argc - 1), &list->free);
	if (list->b == NULL)
		fail(list);
	i = -1;
	while (++i < argc - 1)
		if (list->a[i] < INT_MIN || list->a[i] > INT_MAX)
			fail(list);
}

void is_dup(t_lists *list, int argc)
{
	int i;
	int j;
	
	i = -1;
	while (++i < argc - 1)
		list->b[i] = list->a[i];
	i = -1;
	while (++i < argc - 1)
	{
		j = i;
		while (++j < argc - 1)
			if (list->a[i] == list->b[j])
				fail(list);
	}
	i = -1;
	while (++i < argc - 1)
		list->b[i] = NAN;
}