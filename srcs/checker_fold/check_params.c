/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:45:56 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/13 19:25:50 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
				return (fail(list));
	}
	return (1);
}

void create_lists(t_lists *list, int argc, char **argv)
{
	int i;
	int j;
	
	list->a = calloc_lst(sizeof(int*) * (argc - 1), &list->free);
	if (list->a == NULL)
		return (fail(list));
	list->b = calloc_lst(sizeof(int*) * (argc - 1), &list->free);
	if (list->b == NULL)
		return (fail(list));
	i = 0;
	j = 0;
	while (++i < argc)
		list->a[j++] = ft_atoi_pushswap(argv[i]);
	i = -1;
	while (++i < argc - 1)
		if (list->a[i] < INT_MIN || list->a[i] > INT_MAX)
			return (fail(list));
	return (1);
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
				return (fail(list));
	}
	i = -1;
	while (++i < argc - 1)
		list->b[i] = 0;
	return (1);
}

char **update_list_inst(char **line, t_lists *list)
{
	char	**new;
	int		i;

	new = calloc_lst((list->n_inst + 1) * sizeof(char *), &list->free);
	i = -1;
	if (list->n_inst > 0)
		while (++i < list->n_inst)
			new[i] = list->inst[i];
	new[i] = ft_strdup_pushswap(line, &list->free);
	list->n_inst++;
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
		list->inst = update_list_inst(&line, list);
		ret = get_next_line(STDIN_FILENO, &line);
	}
	if (ret == -1)
		return (error_gnl(&line, list));
	list->inst = update_list_inst(&line, list);
}

int check_list_inst(t_lists *l)
{
	int i;

	i = -1;
	while (++i < l->n_inst)
	{
		if ((l->inst[i][0] == 's' && l->inst[i][1] == 'a' && l->inst[i][2] = 0)
			|| (l->inst[i][0] == 's' && l->inst[i][1] == 'b' && l->inst[i][2] = 0)
			|| (l->inst[i][0] == 's' && l->inst[i][1] == 's' && l->inst[i][2] = 0)
			|| (l->inst[i][0] == 'p' && l->inst[i][1] == 'a' && l->inst[i][2] = 0)
			|| (l->inst[i][0] == 'p' && l->inst[i][1] == 'b' && l->inst[i][2] = 0)
			|| (l->inst[i][0] == 'r' && l->inst[i][1] == 'a' && l->inst[i][2] = 0)
			|| (l->inst[i][0] == 'r' && l->inst[i][1] == 'b' && l->inst[i][2] = 0)
			|| (l->inst[i][0] == 'r' && l->inst[i][1] == 'r' && l->inst[i][2] = 0)
	}
}

void check_params(t_lists *list, int argc, char **argv)
{
	int ret;
	char *line;
	
	isaint(list, argc, argv);
	create_list(list, argc, argv);
	is_dup(list, argc);
	create_list_inst(list);
	check_list_inst(list);
}