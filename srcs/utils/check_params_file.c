/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:44:54 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/27 13:46:13 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	isaint_file(t_lists *list, char **split)
{
	int	i;
	int	j;

	i = -1;
	while (split[++i] != NULL)
	{
		j = 0;
		if (split[i][j] == '-')
			j++;
		while (split[i][j])
			if (!ft_isdigit(split[i][j++]))
				fail(list);
	}
	list->nmax = i;
}

static void	create_lists_file(t_lists *list, char **split)
{
	int	i;

	list->na = list->nmax;
	list->nb = 0;
	list->a = calloc_lst(sizeof(long *) * (list->nmax), &list->free);
	if (list->a == NULL)
		fail(list);
	i = -1;
	while (++i < list->nmax)
		list->a[i] = ft_atoi_pushswap(split[i]);
	list->b = calloc_lst(sizeof(long *) * (list->nmax), &list->free);
	if (list->b == NULL)
		fail(list);
	i = -1;
	while (++i < list->nmax)
		if (list->a[i] < INT_MIN || list->a[i] > INT_MAX)
			fail(list);
}

static void	is_dup_file(t_lists *list)
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

void	check_parameters_file(int argc, char **argv, t_lists *list)
{
	char	**split;
	char	*line;
	int		fd;
	int		ret;
	int		i;

	fd = open(argv[argc - 1], O_RDONLY);
	line = NULL;
	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (error_gnl(&line, list));
	split = ft_split(line, ' ');
	free(line);
	isaint_file(list, split);
	create_lists_file(list, split);
	is_dup_file(list);
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
