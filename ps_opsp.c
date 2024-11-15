/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opsp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:05:27 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/15 16:37:59 by dvauthey         ###   ########.fr       */
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

void	optocall(char *op, t_dbllist **a, t_dbllist **b)
{
	if (!ft_strncmp(op, sa, 3))
		fct_sab(a);
	if (!ft_strncmp(op, sb, 3))
		fct_sab(b);
	if (!ft_strncmp(op, ss, 3))
		fct_ss(a, b);
	if (!ft_strncmp(op, pa, 3))
		fct_pab(a);
	if (!ft_strncmp(op, pb, 3))
		fct_pab(b);
	if (!ft_strncmp(op, ra, 3))
		fct_rab(a);
	if (!ft_strncmp(op, rb, 3))
		fct_rab(b);
	if (!ft_strncmp(op, rr, 3))
		fct_rr(a, b);
	if (!ft_strncmp(op, rra, 3))
		fct_rrab(a);
	if (!ft_strncmp(op, rrb, 3))
		fct_rrab(b);
	if (!ft_strncmp(op, sa, 3))
		fct_rrr(a, b);
}
