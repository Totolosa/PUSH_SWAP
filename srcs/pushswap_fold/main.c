/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:00:19 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/26 17:40:30 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_lists	list;

	ft_bzero(&list, sizeof(t_lists));
	list.prog = 'p';
	isaint(&list, argc, argv);
	create_lists(&list, argc, argv);
	is_dup(&list);
	if (list.na > 1)
		generate_list_inst(&list);
	ft_lstclear(&list.free, free);
	return (0);
}
