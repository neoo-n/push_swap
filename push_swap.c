/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:57:25 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/20 16:07:28 by dvauthey         ###   ########.fr       */
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

static void	threeorder(t_dbllist **a, t_dbllist **b, char *s)
{
	t_dbllist *temp;

	temp = *a;
	if (!ft_strncmp(s, "b", 2))
		temp = *b;
	if (temp->number < temp->next->number)
	{
		if (temp->next->number > (temp->next->next)->number)
		{
			optocall("rr", s, a, b);
			if (temp->number < (temp->next->next)->number)
				optocall("s", s, a, b);
		}
	}
	else
	{
		if (temp->number < (temp->next->next)->number)
			optocall("s", s, a, b);
		else
		{
			optocall("r", s, a, b);
			if (temp->next->number > (temp->next->next)->number)
				optocall("s", s, a, b);
		}
	}
}

static void	ordering(t_dbllist **a, t_dbllist **b, int indexa)
{
	int	lena;
	int	lenb;
	int	indexb;

	lena = ft_dbllstsize(*a);
	lenb = ft_dbllstsize(*b);
	indexb = placeinb(*b, *a, indexa);
	ft_printf("indexb : %i\n", indexb);
	if (indexa != 0 && indexb != 0)
		double_samerotating(a,  b, &indexa, &indexb);
	if (indexa != 0 || indexa != lena)
		simple_rotating(a, b, &indexa, "a");
	if (indexb != 0 || indexb != lenb)
		simple_rotating(a, b, &indexb, "b");
	optocall("p", "b", a, b);
	/*ft_printf("a : \n");
	ft_putdbllst(*a);
	ft_printf("b : \n");
	ft_putdbllst(*b);
	ft_printf("\n");*/
	if (lenb == 3)
		threeorder(a, b, "b");
	else
		rot_decrease(b);
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
		ft_putdbllst(*a);
	}
	threeorder(a, b, "a");
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
