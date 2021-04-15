/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_pushswap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:30:44 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/15 15:55:14 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_fd_pushswap(long n, int fd)
{
	// if (n > INT_MAX || n < INT_MIN)
	// {
	// 	write(1, " ", 1);
	// 	return ;
	// }
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n <= 9)
		ft_putchar_fd(n + '0', fd);
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
