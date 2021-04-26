/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_repartition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:35:55 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/26 17:56:50 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_lists_before_repartition(t_lists *list)
{
	int	i;

	list->cpy_a = calloc_lst(sizeof(long *) * (list->nmax), &list->free);
	if (list->a == NULL)
		fail(list);
	i = -1;
	while (++i < list->nmax)
		list->cpy_a[i] = list->a[i];
	list->cpy_b = calloc_lst(sizeof(long *) * (list->nmax), &list->free);
	if (list->b == NULL)
		fail(list);
	i = -1;
	while (++i < list->nmax)
		list->cpy_b[i] = list->b[i];
	list->cpy_na = list->na;
	list->cpy_nb = list->nb;
}

void	print_repartition_a2(t_res res, t_lists list)
{
	int	i;

	i = list.nb - 1;
	while (i >= res.pushed_to_b)
		ft_putnbr_fd_pushswap(list.b[i--], 1);
	while (i >= 0)
	{
		write(1, "\033[32m\033[1m", 9);
		ft_putnbr_fd_pushswap(list.b[i--], 1);
		write(1, "\033[0m", 4);
	}
	write(1, "\033[33m||\033[0m ", 12);
	i = -1;
	while (++i < res.rev_in_a)
	{
		write(1, "\033[32m\033[1m", 9);
		ft_putnbr_fd_pushswap(list.a[i], 1);
		write(1, "\033[0m", 4);
	}
	while (i < list.na)
		ft_putnbr_fd_pushswap(list.a[i++], 1);
	write(1, "\n\n", 2);
}

void	print_repartition_a(int to_treat, t_res res, t_lists list)
{
	int	i;

	write(1, "\033[1m\nSORT \033[33mA\033[0m :\t", 23);
	i = list.cpy_nb - 1;
	while (i >= 0)
		ft_putnbr_fd_pushswap(list.cpy_b[i--], 1);
	write(1, "\033[33m||\033[0m ", 12);
	i = -1;
	while (++i < to_treat)
	{
		write(1, "\033[31m\033[1m", 9);
		ft_putnbr_fd_pushswap(list.cpy_a[i], 1);
		write(1, "\033[0m", 4);
	}
	while (i < list.cpy_na)
		ft_putnbr_fd_pushswap(list.cpy_a[i++], 1);
	write(1, "  \033[36m-->\033[0m   ", 17);
	print_repartition_a2(res, list);
}

static void	print_repartition_b2(t_res res, t_lists list)
{
	int	i;

	i = list.nb - 1;
	while (i >= res.rev_in_b)
		ft_putnbr_fd_pushswap(list.b[i--], 1);
	while (i >= 0)
	{
		write(1, "\033[32m\033[1m", 9);
		ft_putnbr_fd_pushswap(list.b[i--], 1);
		write(1, "\033[0m", 4);
	}
	write(1, "\033[33m||\033[0m ", 12);
	i = -1;
	while (++i < res.pushed_to_a)
	{
		write(1, "\033[32m\033[1m", 9);
		ft_putnbr_fd_pushswap(list.a[i], 1);
		write(1, "\033[0m", 4);
	}
	while (i < list.na)
		ft_putnbr_fd_pushswap(list.a[i++], 1);
	write(1, "\n\n", 2);
}

void	print_repartition_b(int to_treat, t_res res, t_lists list)
{
	int	i;

	write(1, "\033[1m\nSORT \033[33mB\033[0m :\t", 23);
	i = list.cpy_nb - 1;
	while (i >= to_treat)
		ft_putnbr_fd_pushswap(list.cpy_b[i--], 1);
	while (i >= 0)
	{
		write(1, "\033[31m\033[1m", 9);
		ft_putnbr_fd_pushswap(list.cpy_b[i--], 1);
		write(1, "\033[0m", 4);
	}
	write(1, "\033[33m||\033[0m ", 12);
	i = -1;
	while (++i < list.cpy_na)
		ft_putnbr_fd_pushswap(list.cpy_a[i], 1);
	write(1, "  \033[36m-->\033[0m   ", 17);
	print_repartition_b2(res, list);
}
