/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbllist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:40:36 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/12 13:50:52 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dbllstsize(t_dbllist *lst)
{
	int		count;
	t_dbllist	*next_el;

	count = 0;
	next_el = lst;
	while (next_el)
	{
		next_el = next_el->next;
		count++;
	}
	return (count);
}

t_dbllist	*ft_dbllstnew(int content)
{
	t_dbllist	*res;

	res = (t_dbllist *)ft_calloc(1, sizeof(t_dbllist));
	if (res == NULL)
		return (NULL);
	res->number = content;
	res->next = NULL;
	return (res);
}

void	ft_dbllstadd_back(t_dbllist **lst, t_dbllist *new)
{
	t_dbllist	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (new == NULL)
		return ;
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}