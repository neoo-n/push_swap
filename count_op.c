/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:34:35 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/20 11:06:54 by dvauthey         ###   ########.fr       */
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

int	placeinb(t_dbllist *b, t_dbllist *a, int i)
{
	int	right_index;
	int	n;

	if (!b)
		return (0);
	right_index = 0;
	while (a->index != i)
		a = a->next;
	n = a->number;
	if (n < (ft_dbllstlast(b))->number)
		return (ft_dbllstsize(b));
	while (b)
	{
		if (n > b->number)
		{
			right_index = b->index;
			break ;
		}
		b = b->next;
	}
	return (right_index);
}

static int	count_op(t_dbllist *a, t_dbllist *b, int indexa)
{
	int	lena;
	int	lenb;
	int	nb_op;
	int	indexb;

	lena = ft_dbllstsize(a);
	lenb = ft_dbllstsize(b);
	nb_op = count_rot(lena, indexa);
	indexb = placeinb(b, a, indexa);
	if (((indexb <= lenb / 2) && (indexa > lena / 2)) 
		|| ((indexb > lenb / 2) && (indexa <= lena / 2)))
		nb_op += count_rot(lenb, indexb);
	else
		if(nb_op < count_rot(lenb, indexb))
				nb_op = count_rot(lenb, indexb);
	nb_op++;
	nb_op += count_rot(lenb + 1, indexb);
	return (nb_op);
}

int	indextoorder(t_dbllist *a, t_dbllist *b)
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
