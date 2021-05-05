/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:44:54 by tdayde            #+#    #+#             */
/*   Updated: 2021/05/05 15:23:28 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_option(int argc, char **argv, t_lists *list)
{
	if (argc > 1)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'v' && argv[1][2] == '\0')
			list->show_stack = 1;
		else if (list->prog == 'p'
			&& argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == '\0')
			list->show_repartition = 1;
	}
	if (argc > 2)
	{
		if (argv[2][0] == '-' && argv[2][1] == 'v' && argv[2][2] == '\0')
			list->show_stack = 1;
		else if (list->prog == 'p'
			&& argv[2][0] == '-' && argv[2][1] == 'c' && argv[2][2] == '\0')
			list->show_repartition = 1;
	}
	if (!ft_strncmp(argv[argc - 1], "args.txt", 9))
		list->args_in_file = 1;
}

static void	isaint_main(t_lists *list, int argc, char **argv)
{
	int	i;
	int	j;

	i = list->show_repartition + list->show_stack;
	while (++i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
		{
			j++;
			if (argv[i][j] == '\0')
				fail(list);
		}
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				fail(list);
	}
}

static void	create_lists_main(t_lists *list, int argc, char **argv)
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

static void	is_dup_main(t_lists *list)
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

void	check_parameters_main(int argc, char **argv, t_lists *list)
{
	isaint_main(list, argc, argv);
	create_lists_main(list, argc, argv);
	is_dup_main(list);
}
