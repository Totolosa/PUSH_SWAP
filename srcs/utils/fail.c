/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:35:55 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/15 16:17:47 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	fail(t_lists *list)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_lstclear(&list->free, free);
	exit (1);;
}

void	error_gnl(char **line, t_lists *list)
{
	free(*line);
	fail(list);
}
