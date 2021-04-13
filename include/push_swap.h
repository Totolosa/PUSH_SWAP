/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:33:58 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/13 19:11:21 by tdayde           ###   ########lyon.fr   */
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

void		check_params(t_lists *list, int argc, char **argv);
long long	ft_atoi_pushswap(const char *str);
char		*ft_strdup_pushswap(const char *s, t_list **free);
void		fail(t_lists *list);
void		error_gnl(char **line, t_lists *list);

#endif