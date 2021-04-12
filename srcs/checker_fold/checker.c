/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:48:03 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/13 00:49:25 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int main(int argc, char **argv)
{
	t_lists list;
	
	ft_bzero(&list, sizeof(t_lists));
	if (check_params(&list, argc, argv) == -1)
		return (-1);
	return (0);
}

// A FAIRE :
// - finir checker
// - creer obj pour .o dans libft et dosier general
// - MAJ LIBFT Github