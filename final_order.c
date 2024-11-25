/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:18:03 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/25 11:59:29 by dvauthey         ###   ########.fr       */
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
		ft_printf("bibi phoque encore\n");
		while ((*b)->number > ft_dbllstlast(*a)->number)
		{
			optocall("p", "a", a, b);
			ft_putdbllst(*a);
			ft_printf("-----------------------------------\n");
			ft_putdbllst(*b);
		}
		if (!(*b) || !is_smallest(*a, (*b)->number))
			return ;
		while (ft_dbllstlast(*a)->number > (*b)->number)
		{
			optocall("rr", "a", a, b);
			if (!(*b))
				break ;
		}
		if (!(*b))
			return ;
	}
}

void	bona(t_dbllist **a, t_dbllist **b)
{
	while (*b)
	{
		not_smallest(a, b);
		if (!(*b))
		{
			while (ft_dbllstlast(*a)->number < (*a)->number)
				optocall("rr", "a", a, b);
			break ;
		}
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
