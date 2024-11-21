/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbllist2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:26:10 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/21 11:41:38 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putdbllst(t_dbllist *lst)
{
	t_dbllist	*temp;

	temp = lst;
	if (!temp)
		return ;
	while (temp)
	{
		ft_printf("%i\n", temp->number);
		temp = temp->next;
	}
}

t_dbllist	*ft_dbllstcpy(t_dbllist *a)
{
	t_dbllist	*el;
	t_dbllist	*temp;

	while (a)
	{
		ft_printf()
		el = ft_dbllstnew(a->number);
		ft_dbllstadd_back(&temp, el);
		a = a->next;
	}
	return (temp);
}