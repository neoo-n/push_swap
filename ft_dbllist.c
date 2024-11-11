/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbllist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:40:36 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/11 18:41:21 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dbllstsize(t_dbllist *lst)
{
	int		count;
	t_list	*next_el;

	count = 0;
	next_el = lst;
	while (next_el != NULL)
	{
		next_el = next_el->next;
		count++;
	}
	return (count);
}