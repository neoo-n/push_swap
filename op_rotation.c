/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:45:33 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/25 13:49:56 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_rotating(t_dbllist **a, t_dbllist **b, int *indexl, char *s)
{
	int	len;

	if (!ft_strncmp(s, "a", 2))
		len = ft_dbllstsize(*a);
	if (!ft_strncmp(s, "b", 2))
		len = ft_dbllstsize(*b);
	if (*indexl <= len / 2)
	{
		while (*indexl > 0)
		{
			optocall("r", s, a, b);
			(*indexl)--;
		}
	}
	else if (len - *indexl > 0)
	{
		while (len - *indexl > 0)
		{
			optocall("rr", s, a, b);
			(*indexl)++;
		}
	}
}

void	rot_decrease(t_dbllist **b)
{
	int			biggest;
	int			index_biggest;
	t_dbllist	*temp;
	
	biggest = (*b)->number;
	index_biggest = 0;
	temp = *b;
	while (temp)
	{
		if (biggest < temp->number)
		{
			biggest = temp->number;
			index_biggest = temp->index;
		}
		temp = temp->next;
	}
	simple_rotating(NULL, b, &index_biggest, "b");	
}

static void	double_diffrotating(t_dbllist **a, t_dbllist **b, int *indexa, int *indexb)
{
	if ((*indexb <= ft_dbllstsize(*b) / 2) && (*indexa > ft_dbllstsize(*a) / 2))
	{
		simple_rotating(a, b, indexb, "b");
		simple_rotating(a, b, indexa, "a");
	}
	else if ((*indexb > ft_dbllstsize(*b) / 2) && (*indexa <= ft_dbllstsize(*a) / 2))
	{
		simple_rotating(a, b, indexb, "b");
		simple_rotating(a, b, indexa, "a");	
	}
}

void	double_samerotating(t_dbllist **a, t_dbllist **b, int *indexa, int *indexb)
{
	if ((*indexb <= ft_dbllstsize(*b) / 2) && (*indexa <= ft_dbllstsize(*a) / 2)) 
	{
		while (*indexb != 0 && *indexa != 0)
		{
			optocall("rr", NULL, a, b);
			(*indexb)--;
			(*indexa)--;
		}
	}
	else if ((*indexb > ft_dbllstsize(*b) / 2) && (*indexa > ft_dbllstsize(*a) / 2))
	{
		while (ft_dbllstsize(*b) - *indexb > 0 && ft_dbllstsize(*a) - *indexa > 0)
		{
			optocall("rrr", NULL, a, b);
			(*indexb)++;
			(*indexa)++;
		}
	}
	double_diffrotating(a, b, indexa, indexb);
}
