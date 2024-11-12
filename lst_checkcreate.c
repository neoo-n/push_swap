/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_checkcreate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:11:43 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/12 16:17:33 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//t_dbllist	*check_arg2(char *a)
//{

//}

t_dbllist	*check_argm2(int len, char **argv, t_dbllist **a)
{
	int			i;
	t_dbllist	*new_el;

	i = 1;
	new_el = NULL;
	while (i <= len)
	{
		new_el = ft_dbllstnew(ft_atoi(argv[i]));
		ft_dbllstadd_back(a, new_el);
		i++;
	}
	return (*a);
}