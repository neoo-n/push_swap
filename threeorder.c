/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threeorder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:16:53 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/25 11:30:57 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	firstcase(t_dbllist *temp, t_dbllist **a, t_dbllist **b, char *s)
{
	if (temp->next->number > (temp->next->next)->number)
	{
		optocall("rr", s, a, b);
		if (temp->number < (temp->next->next)->number)
			optocall("s", s, a, b);
	}	
}

static void	secondcase(t_dbllist *temp, t_dbllist **a, t_dbllist **b, char *s)
{
	if (temp->number < (temp->next->next)->number)
		optocall("s", s, a, b);
	else
	{
		optocall("r", s, a, b);
		if (temp->next->number > (temp->next->next)->number)
			optocall("s", s, a, b);
	}
}

void	threeorder(t_dbllist **a, t_dbllist **b, char *s)
{
	t_dbllist *temp;

	temp = NULL;
	if (!ft_strncmp(s, "a", 2))
		ft_dbllstcpy(*a, &temp);
	if (!ft_strncmp(s, "b", 2))
		ft_dbllstcpy(*b, &temp);
	if (temp->number < temp->next->number)
		firstcase(temp, a, b, s);
	else
		secondcase(temp, a, b, s);
	ft_dbllstclear(&temp);
}
