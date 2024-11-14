/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:59:18 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/14 11:33:17 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pour 100 : 700 et pour 500 : 5500
int	main(int argc, char **argv)
{
	t_dbllist	*a;
	t_dbllist	*b;
	t_dbllist	*el;

	a = NULL;
	b = NULL;
	el = ft_dbllstnew(3);
	ft_dbllstadd_back(&b, el);
	el = ft_dbllstnew(4);
	ft_dbllstadd_back(&b, el);
	el = ft_dbllstnew(5);
	ft_dbllstadd_back(&b, el);
	if (argc < 2)
		return (0);
	check_argm2(argc - 1, argv, &a);
	ft_printf("Before : \n");
	ft_printf("a\n");
	ft_putdbllst(a);
	ft_printf("\n");
	ft_printf("b : \n");
	ft_putdbllst(b);

	ft_printf("\n");
	fct_pab(&a, &b);
	ft_printf("After : \n");
	ft_printf("a\n");
	ft_putdbllst(a);
	ft_printf("\n");
	ft_printf("b : \n");
	ft_putdbllst(b);

	return (0);
}
