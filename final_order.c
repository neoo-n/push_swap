/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:18:03 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/22 15:09:19 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_smallest(t_dbllist *a, int n)
{
	while (a->next)
	{
		ft_printf("lllllllllll\n");
		if (a->number < n)
			return (0);
		a = a->next;
	}
	return (1);
}

void	bona(t_dbllist **a, t_dbllist **b)
{
	ft_printf("is_smallest : %i\n", is_smallest(*a, (*b)->number));
	ft_printf("a : %i, b : %i\n", (*a)->number, (*b)->number);
	while (b && !is_smallest(*a, (*b)->number))
	{
		ft_printf("hiiii\n");
		while (b && (*b)->number > ft_dbllstlast(*a)->number)
			optocall("p", "a", a, b);
		while (ft_dbllstlast(*a)->number > (*b)->number)
			optocall("rr", "a", a, b);
	}
	while (b && is_smallest(*a, (*b)->number))
	{
		ft_printf("jjjjjjj\n");
		optocall("p", "a", a, b);
		if (b)
			ft_printf("grr\n");
	}
}