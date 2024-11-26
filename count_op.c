/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:34:35 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/26 16:12:29 by dvauthey         ###   ########.fr       */
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
	int			indexb;
	int			n;
	t_dbllist	*temp;

	if (!b)
		return (0);
	indexb = 0;
	temp = NULL;
	ft_dbllstcpy(b, &temp);
	while (a->index != i)
		a = a->next;
	n = a->number;
	temp = temp->next;
	while (temp != NULL)
	{
		if (n > temp->number && n < temp->prev->number)
			return (temp->index);
		temp = temp->next;
	}
	if (which_biggest(b, n, &indexb))
		return (indexb);
	else if (which_smallest(b, n, &indexb))
		return (indexb);
	ft_dbllstclear(&temp);
	return (0);
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
	return (nb_op);
}

int	indextoorder(t_dbllist *a, t_dbllist *b)
{
	int	i;
	int	lena;
	int	indexright;
	int	nb;
	t_dbllist	*temp;

	i = 0;
	lena = ft_dbllstsize(a);
	indexright = 0;
	nb = count_op(a, b, a->index);
	temp = NULL;
	ft_dbllstcpy(a, &temp);
	while (i < lena)
	{
		if (count_op(a, b, temp->index) < nb)
		{
			nb = count_op(a, b, temp->index);
			indexright = temp->index;
		}
		i++;
		temp = temp->next;
	}
	ft_dbllstclear(&temp);
	return (indexright);
}
