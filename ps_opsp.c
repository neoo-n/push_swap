/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opsp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:05:27 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/21 11:27:45 by dvauthey         ###   ########.fr       */
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

static void	index_right(t_dbllist **lst)
{
	int	i;

	i = 0;
	if (!(*lst))
		return ;
	while ((*lst)->next)
	{
		(*lst)->index = i;
		i++;
		*lst = (*lst)->next;
	}
	while ((*lst)->prev)
		*lst = (*lst)->prev;
}

void	fct_pab(t_dbllist **a, t_dbllist **b)
{
	t_dbllist	*tempa;
	t_dbllist	*tempb;

	if (!(*a))
		return ;
	tempa = ft_dbllstcpy(*a);
	free(a);
	tempb = ft_dbllstcpy(*b); 
	free(b);
	*b = ft_dbllstnew(tempa->number);
	*a = ft_dbllstcpy(tempa->next);
	if (!(*a))
		(*a)->prev = NULL;
	(*b)->next = ft_dbllstcpy(tempb);
	if (tempb)
		((*b)->next)->prev = *b;
	index_right(a);
	ft_printf("a : \n");
	ft_putdbllst(*a);
	index_right(b);
	ft_dbllstclear(&tempa);
	ft_dbllstclear(&tempb);
}

void	optocall(char *op, char *letter, t_dbllist **a, t_dbllist **b)
{
	if (!ft_strncmp(op, "ss", 3))
		fct_ss(a, b);
	else if (!ft_strncmp(op, "s", 2) && !ft_strncmp(letter, "a", 2))
		fct_sab(a);
	else if (!ft_strncmp(op, "s", 2) && !ft_strncmp(letter, "b", 2))
		fct_sab(b);
	else if (!ft_strncmp(op, "p", 2) && !ft_strncmp(letter, "a", 2))
		fct_pab(b, a);
	else if (!ft_strncmp(op, "p", 2) && !ft_strncmp(letter, "b", 2))
		fct_pab(a, b);
	else if (!ft_strncmp(op, "rrr", 4))
		fct_rrr(a, b);
	else if (!ft_strncmp(op, "rr", 3) && !ft_strncmp(letter, "a", 2))
		fct_rrab(a);
	else if (!ft_strncmp(op, "rr", 3) && !ft_strncmp(letter, "b", 2))
		fct_rrab(b);
	else if (!ft_strncmp(op, "rr", 3))
		fct_rr(a, b);
	else if (!ft_strncmp(op, "r", 2) && !ft_strncmp(letter, "a", 2))
		fct_rab(a);
	else if (!ft_strncmp(op, "r", 2) && !ft_strncmp(letter, "b", 2))
		fct_rab(b);
	ft_printf("%s%s\n", op, letter);
}
