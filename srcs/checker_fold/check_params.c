/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:45:56 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/14 17:52:02 by tdayde           ###   ########lyon.fr   */
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

char **update_list_inst(char **line, t_lists *list)
{
	char	**new;
	int		i;

	new = calloc_lst((list->n_ins + 1) * sizeof(char *), &list->free);
	i = 0;
	if (list->n_ins > 0)
		while (i < list->n_ins)
		{
			new[i] = list->ins[i];
			i++;
		}
	new[i] = ft_strdup_pushswap(*line, &list->free);
	list->n_ins++;
	free(*line);
	*line = NULL;
	return (new);
}

void create_list_inst(t_lists *list)
{
	int ret;
	char *line;

	line = NULL;
	ret = get_next_line(STDIN_FILENO, &line);
	while (ret > 0)
	{
		list->ins = update_list_inst(&line, list);
		ret = get_next_line(STDIN_FILENO, &line);
	}
	if (ret == -1)
		return (error_gnl(&line, list));
	list->ins = update_list_inst(&line, list);
}

void check_list_inst(t_lists *l)
{
	int i;

	i = 0;
	while (i < l->n_ins)
	{
		if ((l->ins[i][0] == 's' && l->ins[i][1] == 'a' && l->ins[i][2] == 0)
			|| (l->ins[i][0] == 's' && l->ins[i][1] == 'b' && l->ins[i][2] == 0)
			|| (l->ins[i][0] == 's' && l->ins[i][1] == 's' && l->ins[i][2] == 0)
			|| (l->ins[i][0] == 'p' && l->ins[i][1] == 'a' && l->ins[i][2] == 0)
			|| (l->ins[i][0] == 'p' && l->ins[i][1] == 'b' && l->ins[i][2] == 0)
			|| (l->ins[i][0] == 'r' && l->ins[i][1] == 'a' && l->ins[i][2] == 0)
			|| (l->ins[i][0] == 'r' && l->ins[i][1] == 'b' && l->ins[i][2] == 0)
			|| (l->ins[i][0] == 'r' && l->ins[i][1] == 'r' && l->ins[i][2] == 0)
			|| (l->ins[i][0] == 'r' && l->ins[i][1] == 'r' && l->ins[i][2] == 0)
			|| (l->ins[i][0] == 'r' && l->ins[i][1] == 'r'
				&& l->ins[i][2] == 'a' && l->ins[i][3] == 0)
			|| (l->ins[i][0] == 'r' && l->ins[i][1] == 'r'
				&& l->ins[i][2] == 'b' && l->ins[i][3] == 0)
			|| (l->ins[i][0] == 'r' && l->ins[i][1] == 'r'
				&& l->ins[i][2] == 'r' && l->ins[i][3] == 0))
			i++;
		else
			fail(l);
	}
}

void check_params(t_lists *list, int argc, char **argv)
{
	isaint(list, argc, argv);
	create_lists(list, argc, argv);
	is_dup(list, argc);
	create_list_inst(list);
	check_list_inst(list);
}