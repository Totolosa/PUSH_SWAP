/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:45:56 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/26 17:53:15 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**update_list_inst(char **line, t_lists *list)
{
	char	**new;
	int		i;

	new = calloc_lst((list->n_ins + 1) * sizeof(char *), &list->free);
	i = -1;
	while (++i < list->n_ins)
		new[i] = list->ins[i];
	new[i] = ft_strdup_pushswap(*line, &list->free);
	list->n_ins++;
	free(*line);
	*line = NULL;
	return (new);
}

void	create_list_inst(t_lists *list)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = get_next_line(STDIN_FILENO, &line);
	while (ret > 0)
	{
		list->ins = update_list_inst(&line, list);
		ret = get_next_line(STDIN_FILENO, &line);
	}
	if (ret == -1)
		return (error_gnl(&line, list));
	free(line);
}

void	check_list_inst(t_lists *l)
{
	int	i;

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
