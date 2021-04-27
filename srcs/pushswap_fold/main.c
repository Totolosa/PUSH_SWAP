/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:00:19 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/27 12:11:38 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_lists	list;

	ft_bzero(&list, sizeof(t_lists));
	list.prog = 'p';
	check_option(argc, argv, &list);
	if (list.args_in_file == 1)
		check_parameters_file(argc, argv, &list);
	else
		check_parameters_main(argc, argv, &list);
	if (list.na > 1)
		generate_list_inst(&list);
	ft_lstclear(&list.free, free);
	return (0);
}
