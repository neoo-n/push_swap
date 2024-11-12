/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:05:27 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/12 10:03:46 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dbllist	*fct_sab(t_dbllist **a)
{
	int	len;
	int	temp;

	len = ft_dbllstsize(*a);
	if (len < 2)
		return (*a);
	temp = ((*a)->next)->number;
	((*a)->next)->number = (*a)->number;
	(*a)->number = temp;
	return (*a);
}

void	fct_ss(t_dbllist *a, t_dbllist *b)
{
	fct_sab(&a);
	fct_sab(&b);
}

/*t_dbllist	*fct_pab(t_dbllist *a, t_dbllist *b)
{
	t_dbllist	*temp;
	int		len;

	len = ft_dbllstsize(b); 
	temp = (t_dbllist *)ft_calloc(1, sizeof(t_dbllist));

	return 
}*/