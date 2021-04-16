/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:33:58 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/16 17:12:23 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

# define NAN ((long long)INT_MAX + (long long)1)

typedef struct s_lists
{
	long	*a;
	long	*b;
	int		na;
	int		nb;
	int		nmax;
	char	**ins;
	int		n_ins;
	t_list	*free;
}	t_lists;


void		generate_list_inst(t_lists *list);
void		check_if_ok(t_lists *list);

void		isaint(t_lists *list, int argc, char **argv);
void		create_lists(t_lists *list, int argc, char **argv);
void		is_dup(t_lists *list, int argc);
void		create_list_inst(t_lists *list);
void		check_list_inst(t_lists *l);

void		sa_inst(t_lists *list);
void		sb_inst(t_lists *list);
void		ss_inst(t_lists *list);
void		pa_inst(t_lists *list);
void		pb_inst(t_lists *list);
void		ra_inst(t_lists *list);
void		rb_inst(t_lists *list);
void		rr_inst(t_lists *list);
void		rra_inst(t_lists *list);
void		rrb_inst(t_lists *list);
void		rrr_inst(t_lists *list);

long		ft_atoi_pushswap(const char *str);
char		*ft_strdup_pushswap(const char *s, t_list **free);
void		ft_putnbr_fd_pushswap(long n, int fd);
void		fail(t_lists *list);
void		error_gnl(char **line, t_lists *list);
void		print_lists(t_lists list);
void		print_instructions(t_lists list);

#endif