/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:35:00 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/15 13:51:11 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	notvalid()
{
	ft_printf("Error\n");
	exit(1);
}

static void	is_minmax(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (s[0] == '-')
	{
		if (len > 11 || (len == 11 && ft_strncmp(s, "-2147483648", 11) > 0))
			notvalid();
	}
	else
	{
		if (len > 10 || (len == 10 && ft_strncmp(s, "2147483647", 10) > 0))
			notvalid();
	}
}

void	isnumber(char *s)
{
	int		i;

	i = 0;
	if (!s || s[0] == '\0')
		notvalid();
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			notvalid();
		i++;
	}
	is_minmax(s);	
}

void	is_alreadyin(t_dbllist **a, int n)
{
	t_dbllist	*temp;

	temp = *a;
	if (!(*a))
		return ;
	while (temp)
	{
		if (temp->number == n)
			notvalid();
		temp = temp->next;
	}
}
