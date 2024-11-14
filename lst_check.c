/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:35:00 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/13 13:46:25 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	notvalid()
{
	ft_printf("Error\n");
	exit(1);
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
	if (ft_atol(s) > 2147483647 || ft_atol(s) < -2147483648)
		notvalid();
}

void	is_alreadyin(t_dbllist *a, int n)
{
	while (a)
	{
		if (a->number == n)
			notvalid();
		a = a->next;
	}
}
