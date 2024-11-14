/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbllist2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:20:23 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/14 13:30:01 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_dbllstdellast(t_dbllist **a)
{
	while (((*a)->next)->next)
		(*a) = (*a)->next;
	(*a)->number = 0;
	(*a)->next = NULL;
	free((*a)->next);
	while ((*a)->prev)
		(*a) = (*a)->prev;
}