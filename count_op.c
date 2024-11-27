/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:34:35 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/27 15:32:13 by dvauthey         ###   ########.fr       */
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

static int	tempbetween(int n, t_dbllist *temp,
	int *indexb, t_dbllist *temptemp)
{
	if (temp->number < n && ft_dbllstlast(temp)->number > n)
	{
		ft_dbllstclear(&temptemp);
		return (1);
	}
	temp = temp->next;
	while (temp != NULL)
	{
		if (n > temp->number && n < temp->prev->number)
		{
			*indexb = temp->index;
			ft_dbllstclear(&temptemp);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

int	placeinb(t_dbllist *b, t_dbllist *a, int i)
{
	int			indexb;
	int			n;
	t_dbllist	*temp;
	t_dbllist	*temptemp;

	if (!b)
		return (0);
	indexb = 0;
	temp = NULL;
	ft_dbllstcpy(b, &temp);
	temptemp = temp;
	while (a->index != i)
		a = a->next;
	n = a->number;
	if (tempbetween(n, temp, &indexb, temptemp))
		return (indexb);
	if (which_biggest(b, n, &indexb))
		return (ft_dbllstclear(&temptemp), indexb);
	else if (which_smallest(b, n, &indexb))
		return (ft_dbllstclear(&temptemp), indexb);
	ft_dbllstclear(&temptemp);
	return (indexb);
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
		if (nb_op < count_rot(lenb, indexb))
			nb_op = count_rot(lenb, indexb);
	nb_op++;
	return (nb_op);
}

int	indextoorder(t_dbllist *a, t_dbllist *b)
{
	int			indexright;
	int			nb;
	t_dbllist	*temp;
	t_dbllist	*temptemp;

	indexright = 0;
	nb = count_op(a, b, a->index);
	temp = NULL;
	ft_dbllstcpy(a, &temp);
	temptemp = temp;
	while (temp)
	{
		if (count_op(a, b, temp->index) < nb)
		{
			nb = count_op(a, b, temp->index);
			indexright = temp->index;
		}
		temp = temp->next;
	}
	ft_dbllstclear(&temptemp);
	return (indexright);
}
