/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:08:13 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/15 11:40:39 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fct_rab(t_dbllist **a)
{
	int	first;

	if (!(*a))
		return ;
	first = (*a)->number;
	while ((*a)->next)
	{
		*a = (*a)->next;
		((*a)->prev)->number = (*a)->number;
	}
	(*a)->number = first;
	while ((*a)->prev)
		*a = (*a)->prev;
}

void	fct_rr(t_dbllist **a, t_dbllist **b)
{
	fct_rab(a);
	fct_rab(b);
}

void	fct_rrab(t_dbllist **a)
{
	int	last;

	if (!(*a))
		return ;
	while ((*a)->next)
		*a = (*a)->next;
	last = (*a)->number;
	while ((*a)->prev)
	{
		*a = (*a)->prev;
		((*a)->next)->number = (*a)->number;
	}
	(*a)->number = last;
}

void	fct_rrr(t_dbllist **a, t_dbllist **b)
{
	fct_rrab(a);
	fct_rrab(b);
}