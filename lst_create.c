/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:11:43 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/27 15:35:35 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*freesplit(char **res)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (res[j])
		j++;
	while (i <= j)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static void	conditionnum(char **res, int i, t_dbllist **a)
{
	if (!isnumber(res[i]) || is_alreadyin(a, ft_atoi(res[i])))
	{
		freesplit(res);
		notvalid(a);
	}
}

t_dbllist	*check_arg2(char *av, t_dbllist **a)
{
	int			i;
	t_dbllist	*new_el;
	char		**res;

	i = 0;
	res = ft_split(av, ' ');
	if (!res)
		notvalid(a);
	if (!res[0])
	{
		freesplit(res);
		notvalid(a);
	}
	while (res && res[i])
	{
		conditionnum(res, i, a);
		new_el = ft_dbllstnew(ft_atoi(res[i]));
		ft_dbllstadd_back(a, new_el);
		i++;
	}
	freesplit(res);
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
			if (!isnumber(argv[i]) || is_alreadyin(a, ft_atoi(argv[i])))
				notvalid(a);
			new_el = ft_dbllstnew(ft_atoi(argv[i]));
			ft_dbllstadd_back(a, new_el);
		}
		i++;
	}
}
