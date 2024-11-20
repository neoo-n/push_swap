/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:45:33 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/20 11:52:52 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_rotating(t_dbllist **a, )

void	double_rotating(t_dbllist **a, t_dbllist **b, int indexa, int indexb)
{
	if ((indexb <= ft_dbllstsize(*b) / 2) && (indexa <= ft_dbllstsize(*a) / 2)) 
	{
		while (indexb != 0 && indexa != 0)
		{
			optocall("rr", NULL, a, b);
			indexb--;
			indexa--;
		}
	}
	else if ((indexb > ft_dbllstsize(*b) / 2) && (indexa > ft_dbllstsize(*a) / 2))
	{
		while (indexb != 0 && indexa != 0)
		{
			optocall("rrr", NULL, a, b);
			indexb--;
			indexa--;
		}
	}
	simple_rotating();
}
