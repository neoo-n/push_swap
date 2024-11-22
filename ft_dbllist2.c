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
