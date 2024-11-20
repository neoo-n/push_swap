/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:57:25 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/20 11:46:48 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_ordered(t_dbllist *a)
{
	while (a->next && a->number < (a->next)->number)
		a = a->next;
	if (!(a->next))
		return (1);
	else
		return (0);
}

static void	threeorder(t_dbllist **lst, char *s)
{
	int	c[3];

	c[0] = (*lst)->number;
	c[1] = (*lst)->next->number;
	c[2] = (*lst)->next->next->number;
	if (c[0] < c[1])
	{
		if (c[1] > c[2])
		{
			optocall("rr", s, lst, NULL);
			if (c[0] < c[2])
				optocall("s", s, lst, NULL);
		}
	}
	else
	{
		if (c[0] < c[2])
			optocall("s", s, lst, NULL);
		else
		{
			optocall("r", s, lst, NULL);
			if (c[1] > c[2])
				optocall("s", s, lst, NULL);
		}
	}
}

static void	ordering(t_dbllist **a, t_dbllist **b, int indexa)
{
	int	indexb;

	indexb = placeinb(*b, *a, indexa);
	
}

static void	to_order(t_dbllist **a, t_dbllist **b)
{
	if (ft_dbllstsize(*a) == 2)
	{
		optocall("s", "a", a, b);
		return ;
	}
	while (ft_dbllstsize(*a) > 3)
	{
		ordering(a, b, indextoorder(*a, *b));
		ft_printf("bruh\n");
	}
	threeorder(a, "a");
}

void	ft_push_swap(t_dbllist *a)
{
	int	right_index;
	t_dbllist	*b;
//	t_dbllist	*e;

	right_index = 0;
	b = NULL;
/*	e = ft_dbllstnew(66);
	ft_dbllstadd_back(&b, e);
	e = ft_dbllstnew(38);
	ft_dbllstadd_back(&b, e);
	e = ft_dbllstnew(21);
	ft_dbllstadd_back(&b, e);
	ft_putdbllst(b);*/
	ft_printf("\n");
	if (is_ordered(a))
		exit(EXIT_SUCCESS);
	to_order(&a, &b);
//	right_index = indextoorder(a, b);
//	ft_printf("right index : %i\n", right_index);
	ft_putdbllst(a);
	return ;	
}
