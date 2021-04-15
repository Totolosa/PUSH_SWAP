/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:48:03 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/15 16:16:24 by tdayde           ###   ########lyon.fr   */
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
	print_lists(list);

	// printf("\nExec sa :\n");
	// sa_inst(&list);
	// print_lists(list);
	// printf("\nExec sb :\n");
	// sb_inst(&list);
	// print_lists(list);
	// printf("\nExec ss :\n");
	// ss_inst(&list);
	// print_lists(list);
	// printf("\nExec pb pb pb pb :\n");
	// pb_inst(&list);
	// pb_inst(&list);
	// pb_inst(&list);
	// pb_inst(&list);
	// print_lists(list);
	// printf("\nExec pa :\n");
	// pa_inst(&list);
	// print_lists(list);
	// printf("\nExec ra rb :\n");
	// ra_inst(&list);
	// rb_inst(&list);
	// print_lists(list);
	// printf("\nExec rra rrb :\n");
	// rra_inst(&list);
	// rrb_inst(&list);
	// print_lists(list);
	ft_lstclear(&list.free, free);
	return (0);
}

// A FAIRE :
// - finir checker --> OK
// - creer obj pour .o dans libft et dosier general --> OK
// - algo pushswap
// - MAJ LIBFT Github