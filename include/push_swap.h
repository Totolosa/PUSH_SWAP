/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:33:58 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/13 00:19:06 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_lists
{
	long *a;
	long *b;
	char **inst;
	int n_inst;
	t_list *free;
}	t_lists;

int check_params(t_lists *list, int argc, char **argv);
long long	ft_atoi_pushswap(const char *str);
int fail(t_lists *list);
int	error_gnl(char **line, t_lists *list);

#endif