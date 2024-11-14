/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbllist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:40:36 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/14 14:55:14 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dbllstsize(t_dbllist *lst)
{
	int			count;
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
	ft_printf("%i\n", temp->next == NULL);
	temp->next = new;
	new->prev = temp;
}

void	ft_dbllstadd_front(t_dbllist **lst, t_dbllist *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}

void	ft_dbllstdelfirst(t_dbllist **a)
{
	t_dbllist	*a_mod;

	a_mod = (*a)->next;
	(*a)->number = 0;
	((*a)->next)->prev = NULL;
	free(*a);
	*a = a_mod;
}
