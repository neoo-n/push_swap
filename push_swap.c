/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:57:25 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/19 11:50:53 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_ordered(t_dbllist *a)
{
	while (a->next && a->number < (a->next)->number)
		a = a->next;
	if (!(a->next))
		return (0);
	else
		return (1);
}

static int	to_order(t_dbllist *a, t_dbllist *b)
{
	int	indexright;
	int	nb;

	indexright = 0;
	nb = -1;
	while (a->next)
	{
		if (count_op(a, b, a->index) < nb && nb > -1)
		{
			nb = count_op(a, b, a->index);
			indexright = a->index;
		}
	}
	return (indexright);
}

void	ft_push_swap(t_dbllist *a)
{
	int	right_index;
	t_dbllist	*b;

	right_index = 0;
	b = NULL;
	if (is_ordered(a))
		exit(1);
	right_index = to_order(a, b);
	ft_printf("%i\n", right_index);
	return ;	
}
