/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbllist2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:26:10 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/25 17:32:06 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putdbllst(t_dbllist *lst)
{
	if (!lst)
		ft_printf("NULL\n");
	while (lst)
	{
		ft_printf("%i : %i\n",lst->index, lst->number);
		lst = lst->next;
	}
}

void	ft_dbllstcpy(t_dbllist *lst, t_dbllist **temp)
{
	t_dbllist	*el;

	while (lst)
	{
		el = ft_dbllstnew(lst->number);
		ft_dbllstadd_back(temp, el);
		lst = lst->next;
	}
}