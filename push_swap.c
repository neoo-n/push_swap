/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:57:25 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/26 16:13:05 by dvauthey         ###   ########.fr       */
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

static void	ordering(t_dbllist **a, t_dbllist **b, int indexa)
{
	int	lena;
	int	lenb;
	int	indexb;

	lena = ft_dbllstsize(*a);
	lenb = ft_dbllstsize(*b);
	indexb = placeinb(*b, *a, indexa);
	if (indexa != 0 && indexb != 0)
		double_samerotating(a,  b, &indexa, &indexb);
	if (indexa != 0 && indexa != lena)
		simple_rotating(a, b, &indexa, "a");
	if (indexb != 0 && indexb != lenb)
		simple_rotating(a, b, &indexb, "b");
	optocall("p", "b", a, b);
}

static void	to_order(t_dbllist **a, t_dbllist **b)
{
	if (ft_dbllstsize(*a) == 2)
	{
		optocall("s", "a", a, b);
		return ;
	}
	while (ft_dbllstsize(*a) > 3)
		ordering(a, b, indextoorder(*a, *b));
	if (ft_dbllstsize(*b) == 3)
		threeorderdec(a, b, "b");
	else
		rot_decrease(b);
	threeorder(a, b, "a");
	bona(a, b);
}

void	ft_push_swap(t_dbllist *a)
{
	t_dbllist	*b;

	b = NULL;
	if (is_ordered(a))
		exit(EXIT_SUCCESS);
	to_order(&a, &b);
//	ft_putdbllst(a);
	return ;	
}
