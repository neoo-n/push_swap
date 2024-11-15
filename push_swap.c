/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:57:25 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/15 16:13:16 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_ordered(t_dbllist *a)
{
	while (a->next && a->number < (a->next)->number)
		a = a->next;
	if (!(a->next))
		exit(0);
	else
		exit(1);
}

void	ft_push_swap(t_dbllist *a)
{
	is_ordered(a);
	return ;	
}
