/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:23:02 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/22 15:28:45 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instructions(t_lists list)
{
	int i;

	i = -1;
	// write(1, "INSTRUCTIONS :\n", 15);
	while (++i < list.n_ins)
	{
		write(1, list.ins[i], ft_strlen(list.ins[i]));
		write(1, "\n", 1);
	}
}