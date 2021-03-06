/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:48:03 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/27 17:47:50 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_lists	list;

	ft_bzero(&list, sizeof(t_lists));
	list.prog = 'c';
	check_option(argc, argv, &list);
	if (argc == 1 || (argc == 2 && list.show_stack == 1))
		return (0);
	if (list.args_in_file == 1)
		check_parameters_file(argc, argv, &list);
	else
		check_parameters_main(argc, argv, &list);
	create_list_inst(&list);
	check_list_inst(&list);
	check_if_ok(&list);
	ft_lstclear(&list.free, free);
	return (0);
}
