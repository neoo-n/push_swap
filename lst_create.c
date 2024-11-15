/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:11:43 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/15 15:46:55 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dbllist	*check_arg2(char *av, t_dbllist **a)
{
	int			i;
	t_dbllist	*new_el;
	char		**res;

	i = 0;
	res = ft_split(av, ' ');
	if (!res)
		notvalid();
	while (res && res[i])
	{
		isnumber(res[i]);
		is_alreadyin(a, ft_atoi(res[i]));
		new_el = ft_dbllstnew(ft_atoi(res[i]));
		ft_dbllstadd_back(a, new_el);
		i++;
	}
	return (*a);
}

void	check_argm2(int len, char **argv, t_dbllist **a)
{
	int			i;
	t_dbllist	*new_el;

	i = 1;
	new_el = NULL;
	while (i <= len)
	{
		if (ft_strlen(argv[i]) > 1)
			*a = check_arg2(argv[i], a);
		else
		{
			isnumber(argv[i]);
			is_alreadyin(a, ft_atoi(argv[i]));
			new_el = ft_dbllstnew(ft_atoi(argv[i]));
			ft_dbllstadd_back(a, new_el);
		}
		i++;
	}
}
