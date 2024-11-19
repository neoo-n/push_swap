/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:57:25 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/19 17:26:34 by dvauthey         ###   ########.fr       */
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

static int	indextoorder(t_dbllist *a, t_dbllist *b)
{
	int	indexright;
	int	nb;
	t_dbllist	*temp;

	indexright = 0;
	nb = count_op(a, b, a->index);
	temp = a;
	while (temp->next)
	{
		temp = temp->next;
		if (count_op(a, b, temp->index) < nb)
		{
			nb = count_op(a, b, temp->index);
			indexright = temp->index;
		}
	}
	return (indexright);
}

static void	threeorder(t_dbllist **lst)
{
	int	c[3];

	c[0] = (*lst)->number;
	c[1] = (*lst)->next->number;
	c[2] = (*lst)->next->next->number;
	if (c[0] < c[1])
	{
		if (c[1] > c[2])
		{
			optocall("rra", &lst, NULL);
			if (c[0] < c[2])
				optocall("sa", &lst, NULL);
		}
	}
	else
	{
		if (c[0] < c[2])
			optocall("sa", &lst, NULL);
		else
		{
			optocall("ra", &lst, NULL);
			if (c[1] > c[2])
				optocall("sa", &lst, NULL);
		}
	}
}

static void	to_order(t_dbllist *a, t_dbllist *b)
{
	int	lena;

	lena = ft_dbllstsize(a);
	if (lena == 3)
		threeorder(&a);
	else
	{
		
	}
}

void	ft_push_swap(t_dbllist *a)
{
	int	right_index;
	t_dbllist	*b;
	t_dbllist	*e;

	right_index = 0;
	b = NULL;
	e = ft_dbllstnew(66);
	ft_dbllstadd_back(&b, e);
	e = ft_dbllstnew(38);
	ft_dbllstadd_back(&b, e);
	e = ft_dbllstnew(21);
	ft_dbllstadd_back(&b, e);
	ft_putdbllst(b);
	if (is_ordered(a))
		exit(1);
	right_index = indextoorder(a, b);
	ft_printf("right index : %i\n", right_index);
	return ;	
}
