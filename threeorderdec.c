/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threeorderdec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:31:19 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/25 11:38:55 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	firstcasedec(t_dbllist *temp, t_dbllist **a, t_dbllist **b, char *s)
{
	if (temp->next->number < (temp->next->next)->number)
	{
		optocall("rr", s, a, b);
		if (temp->number > (temp->next->next)->number)
			optocall("s", s, a, b);
	}	
}

static void	secondcasedec(t_dbllist *temp, t_dbllist **a, t_dbllist **b, char *s)
{
	if (temp->number < (temp->next->next)->number)
	{
		optocall("r", s, a, b);
		if (temp->next->number < (temp->next->next)->number)
			optocall("s", s, a, b);
	}
	else
		optocall("s", s, a, b);
}

void	threeorderdec(t_dbllist **a, t_dbllist **b, char *s)
{
	t_dbllist *temp;

	temp = NULL;
	if (!ft_strncmp(s, "a", 2))
		ft_dbllstcpy(*a, &temp);
	if (!ft_strncmp(s, "b", 2))
		ft_dbllstcpy(*b, &temp);
	if (temp->number > temp->next->number)
		firstcasedec(temp, a, b, s);
	else
		secondcasedec(temp, a, b, s);
	ft_dbllstclear(&temp);
}
