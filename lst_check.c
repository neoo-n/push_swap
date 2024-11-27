/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:35:00 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/27 15:33:37 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	notvalid(t_dbllist **a)
{
	ft_putendl_fd("Error", 2);
	ft_dbllstclear(a);
	exit(EXIT_FAILURE);
}

static int	is_minmax(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (s[0] == '-')
	{
		if (len > 11 || (len == 11 && ft_strncmp(s, "-2147483648", 11) > 0))
			return (0);
	}
	else
	{
		if (len > 10 || (len == 10 && ft_strncmp(s, "2147483647", 10) > 0))
			return (0);
	}
	return (1);
}

int	isnumber(char *s)
{
	int		i;

	i = 0;
	if (!s || s[0] == '\0')
		return (0);
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	if (!is_minmax(s))
		return (0);
	return (1);
}

int	is_alreadyin(t_dbllist **a, int n)
{
	t_dbllist	*temp;

	temp = *a;
	if (!(*a))
		return (0);
	while (temp)
	{
		if (temp->number == n)
			return (1);
		temp = temp->next;
	}
	return (0);
}
