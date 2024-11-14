/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:08:13 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/14 14:46:12 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fct_rab(t_dbllist **a)
{
	t_dbllist	*first_el;

	first_el = *a;
	ft_dbllstadd_back(a, first_el);
	ft_dbllstdelfirst(a);
}

void	fct_rr(t_dbllist **a, t_dbllist **b)
{
	fct_rab(a);
	fct_rab(b);
}

void	fct_rrab(t_dbllist **a)
{
	t_dbllist *last_el;
	t_dbllist *temp;

	temp = *a;
	while (temp->next)
		temp = temp->next;
	last_el = temp;
	ft_dbllstadd_front(a, last_el);
	ft_dbllstdellast(a);
}