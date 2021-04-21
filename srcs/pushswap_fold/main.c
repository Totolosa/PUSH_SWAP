/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:00:19 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/21 18:02:16 by tdayde           ###   ########lyon.fr   */
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
	generate_list_inst(&list);
	print_instructions(list);
	ft_lstclear(&list.free, free);
	return (0);
}