/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opsp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:05:27 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/15 11:29:00 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fct_sab(t_dbllist **a)
{
	int	len;
	int	temp;

	len = ft_dbllstsize(*a);
	if (len < 2)
		return ;
	temp = ((*a)->next)->number;
	((*a)->next)->number = (*a)->number;
	(*a)->number = temp;

}

void	fct_ss(t_dbllist **a, t_dbllist **b)
{
	fct_sab(a);
	fct_sab(b);
}

void	fct_pab(t_dbllist **a, t_dbllist **b)
{
	t_dbllist	*temp;

	if (!(*a))
		return ;
	temp = *b;
	if (!temp)
		*b = ft_dbllstnew((*a)->number);
	else
		*b = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	(*b)->next = temp;
	if (temp)
		((*b)->next)->prev = *b;
}
