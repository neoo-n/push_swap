/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ckeck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:35:00 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/13 11:49:01 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fct_notvalid()
{
	ft_printf("Error\n");
	exit(1);
}

void	fct_isnumber(char *s)
{
	int		i;

	i = 0;
	if (!s)
		fct_notvalid();
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			fct_notvalid();
		i++;
	}
	if (ft_atol(s) > 2147384647 || ft_atol(s) < -2147483648)
		fct_notvalid();
}