/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:48:03 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/26 17:54:32 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_lists	list;

	ft_bzero(&list, sizeof(t_lists));
	list.prog = 'c';
	isaint(&list, argc, argv);
	create_lists(&list, argc, argv);
	is_dup(&list);
	create_list_inst(&list);
	check_list_inst(&list);
	check_if_ok(&list);
	ft_lstclear(&list.free, free);
	return (0);
}

// A FAIRE :
// - finir checker --> OK
// - creer obj pour .o dans libft et dosier general --> OK
// - algo pushswap --> OK
// - MAJ LIBFT Github
