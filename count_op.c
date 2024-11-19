/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:34:35 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/19 11:52:26 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_rot(int len, int i)
{
	if (i <= (len / 2))
		return (i);
	else
		return (len - i);
}

static int	placeinb(t_dbllist *b, t_dbllist *a, int i)
{
	int	n;

	if (!b)
		return (0);
	while (a->index != i)
		a = a->next;
	n = a->number;
	if (n < (ft_dbllstlast(b))->number)
		return (ft_dbllstsize(b));
	while (b->next)
	{
		if (n > b->number)
			return (b->index);
		b = b->next;
	}
}

int	count_op(t_dbllist *a, t_dbllist *b, int i)
{
	int	lena;
	int	lenb;
	int	nb_op;
	int	indexb;

	lena = ft_dbllstsize(a);
	lenb = ft_dbllstsize(b);
	nb_op = count_rot(lena, i);
	indexb = placeinb(b, a, i);
	if (((indexb <= (lenb + 1) / 2) && (i > lena / 2))
		|| ((indexb > (lenb + 1) / 2) && (i <= lena / 2)))
		nb_op += count_rot(lenb + 1, indexb);
	nb_op++;
	return (nb_op);
}