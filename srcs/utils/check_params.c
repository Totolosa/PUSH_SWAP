/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:44:54 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/26 17:55:43 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_option(int *i, int argc, char **argv, t_lists *list)
{
	if (argc > 1)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'v' && argv[1][2] == '\0')
			list->show_stack = 1;
		else if (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == '\0')
			list->show_repartition = 1;
	}
	if (argc > 2)
	{
		if (argv[2][0] == '-' && argv[2][1] == 'v' && argv[2][2] == '\0')
			list->show_stack = 1;
		else if (argv[2][0] == '-' && argv[2][1] == 'c' && argv[2][2] == '\0')
			list->show_repartition = 1;
	}
	*i += (list->show_repartition + list->show_stack);
}

void	isaint(t_lists *list, int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	check_option(&i, argc, argv, list);
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

void	create_lists(t_lists *list, int argc, char **argv)
{
	int	i;
	int	option;

	option = list->show_repartition + list->show_stack;
	list->nmax = argc - 1 - option;
	list->na = list->nmax;
	list->nb = 0;
	list->a = calloc_lst(sizeof(long *) * (list->nmax), &list->free);
	if (list->a == NULL)
		fail(list);
	i = -1;
	while (++i < list->nmax)
		list->a[i] = ft_atoi_pushswap(argv[i + 1 + option]);
	list->b = calloc_lst(sizeof(long *) * (list->nmax), &list->free);
	if (list->b == NULL)
		fail(list);
	i = -1;
	while (++i < list->nmax)
		if (list->a[i] < INT_MIN || list->a[i] > INT_MAX)
			fail(list);
}

void	is_dup(t_lists *list)
{
	int	i;
	int	j;

	i = -1;
	while (++i < list->nmax)
		list->b[i] = list->a[i];
	i = -1;
	while (++i < list->nmax)
	{
		j = i;
		while (++j < list->nmax)
			if (list->a[i] == list->b[j])
				fail(list);
	}
	i = -1;
	while (++i < list->nmax)
		list->b[i] = NAN;
}
