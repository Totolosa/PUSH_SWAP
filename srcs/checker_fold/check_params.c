/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:45:56 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/12 18:52:45 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void isaint(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		if (argv[i][j] = '-')
			j++;
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				fail();
	}
}

void create_list(int **list, int argc, char **argv)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (++i < argc)
		*(list[j++]) = ft_atoi(argv[i]);
}

void on_limits(int *list, int argc)
{
	int i;
	
	i = -1;
	while (++i < argc)
		if (list[i] < INT_MIN || list > INT_MAX)
			return (fail());
}

void check_params(int argc, char **argv)
{
	long *list;
	
	isaint(argc, argv);
	create_list(&list, argc, argv);
	on_limits(list, argc);
	
}