/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whichsmallbig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:40:15 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/26 16:12:44 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	which_smallest(t_dbllist *b, int n, int *indexb)
{
	int	smallerb;

	if (!b)
		return (0);
	smallerb = b->number;
	*indexb = 1;
	while (b)
	{
		if (b->number < smallerb)
		{
			smallerb = b->number;
			*indexb = b->index + 1;
		}
		if (n > b->number)
			return (0);
		b = b->next;
	}
	return (1);
}

int	which_biggest(t_dbllist *b, int n, int *indexb)
{
	int	biggerb;

	if (!b)
		return (0);
	biggerb = b->number;
	while (b)
	{
		if (b->number > biggerb)
		{
			biggerb = b->number;
			*indexb = b->index;
		}
		if (n < b->number)
			return (0);
		b = b->next;
	}
	return (1);
}