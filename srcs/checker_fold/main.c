/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:48:03 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/14 19:11:40 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_lists(t_lists list)
{
	int i;
	int j;
	int k;
	int max;

	if (list.na >= list.nb)
		max = list.na;
	else 
		max = list.nb;
	i = -1;
	j = 0;
	k = 0;
	while (++i < max)
	{
		if (i >= max - list.na)
			ft_putnbr_fd_pushswap(list.a[j++], STDOUT_FILENO);
		else
			write(1, " ", 1);
		write(1, " ", 1);
		if (i >= max - list.nb)
			ft_putnbr_fd_pushswap(list.b[k++], STDOUT_FILENO);
		else
			write(1, " ", 1);
		write(1, "\n", 1);
	}
	write(1, "- -\n", 4);
	write(1, "a b\n", 4);
}

int main(int argc, char **argv)
{
	t_lists list;
	
	setbuf(stdout, NULL);
	ft_bzero(&list, sizeof(t_lists));
	check_params(&list, argc, argv);
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
// - finir checker => OK
// - creer obj pour .o dans libft et dosier general
// - MAJ LIBFT Github