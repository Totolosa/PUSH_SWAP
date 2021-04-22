/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:48:03 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/22 18:21:13 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_lists list;
	
	setbuf(stdout, NULL);
	ft_bzero(&list, sizeof(t_lists));
	isaint(&list, argc, argv);
	create_lists(&list, argc, argv);
	is_dup(&list, argc);
	create_list_inst(&list);
	check_list_inst(&list);
	check_if_ok(&list);

	// printf("\nInstruction :\n");
	// print_instructions(list);
	// printf("\nLists :\n");
	// print_lists(list);

	ft_lstclear(&list.free, free);
	return (0);
}

// A FAIRE :
// - finir checker --> OK
// - creer obj pour .o dans libft et dosier general --> OK
// - algo pushswap
// - MAJ LIBFT Github

	// else if ((list->b[2] > list->b[1] && list->b[2] < list->b[0]))
	// {
	// 	add_one_ins("pa", list);
	// 	add_one_ins("sb", list);
	// 	add_one_ins("pa", list);
	// 	add_one_ins("pa", list);
	// }
	// else if ((list->b[0] > list->b[2] && list->b[0] < list->b[1]))
	// {
	// 	add_one_ins("rb", list);
	// 	add_one_ins("pa", list);
	// 	add_one_ins("pa", list);
	// 	add_one_ins("rrb", list);
	// 	add_one_ins("pa", list);
	// }
	// else if ((list->b[2] > list->b[1] && list->b[2] < list->b[0]))
	// {
	// 	add_one_ins("rb", list);
	// 	add_one_ins("sb", list);
	// 	add_one_ins("pa", list);
	// 	add_one_ins("rrb", list);
	// 	add_one_ins("pa", list);
	// 	add_one_ins("pa", list);
	// }
	// else if ((list->b[1] > list->b[2] && list->b[1] < list->b[0]))
	// {
	// 	add_one_ins("rb", list);
	// 	add_one_ins("sb", list);
	// 	add_one_ins("pa", list);
	// 	add_one_ins("rrb", list);
	// 	add_one_ins("pa", list);
	// 	add_one_ins("pa", list);
	// }