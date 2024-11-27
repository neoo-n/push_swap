/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:18:03 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/27 15:42:15 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_smallest(t_dbllist *a, int n)
{
	while (a)
	{
		if (a->number < n)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	not_smallest(t_dbllist **a, t_dbllist **b)
{
	while (!is_smallest(*a, (*b)->number))
	{
		while ((*b)->number > ft_dbllstlast(*a)->number)
		{
			optocall("p", "a", a, b);
			if (!(*b))
				return ;
		}
		while (ft_dbllstlast(*a)->number > (*b)->number
			&& !is_smallest(*a, (*b)->number))
		{
			if (ft_dbllstsize(*a) == 3 && (*b)->number < (*a)->next->number)
				optocall("r", "a", a, b);
			else
				optocall("rr", "a", a, b);
			if (!(*b))
				return ;
		}
	}
}

void	bona(t_dbllist **a, t_dbllist **b)
{
	while (*b)
	{
		not_smallest(a, b);
		while (ft_dbllstlast(*a)->number < (*a)->number)
			optocall("rr", "a", a, b);
		if (!(*b))
			break ;
		while (is_smallest(*a, (*b)->number))
		{
			optocall("p", "a", a, b);
			if (!(*b))
				break ;
		}
	}
}
