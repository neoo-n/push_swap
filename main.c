/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:59:18 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/15 16:26:16 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pour 100 : 700 et pour 500 : 5500

int	main(int argc, char **argv)
{
	t_dbllist	*a;
	
	a = NULL;
	if (argc < 2)
		return (0);
	check_argm2(argc - 1, argv, &a);
	ft_putdbllst(a);
	ft_push_swap(a);
	return (0);
}
