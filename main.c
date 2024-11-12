/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:59:18 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/12 16:12:47 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dbllist	*a;

	a = NULL;
	if (argc < 2)
		return (0);
//	if (argc == 2)
//	
	else
	{
		check_argm2(argc - 1, argv, &a);
	}
	ft_putdbllst(a);
	return (0);
}
