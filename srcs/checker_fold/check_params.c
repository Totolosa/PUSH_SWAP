/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:45:56 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/13 00:37:14 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int isaint(t_lists *list, int argc, char **argv)
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

int create_list(t_lists *list, int argc, char **argv)
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

int is_dup(t_lists *list, int argc)
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

int check_params(t_lists *list, int argc, char **argv)
{
	int ret;
	char *line;
	
	if (isaint(list, argc, argv) == -1)
		return (-1);
	if (create_list(list, argc, argv) == -1)
		return (-1);
	if (is_dup(list, argc) == -1)
		return (-1);
	line = NULL;
	ret = get_next_line(STDIN_FILENO, &line);
	while (ret > 0)
	{
		list->n_inst++;
		if (list->n_inst != 0)
			free(list->inst);
		list->inst = calloc_lst(list->n_inst * sizeof(char *), &list->free);
		
	}
	if (ret == -1)
		return (error_gnl(&line, list));
	return (1);
}