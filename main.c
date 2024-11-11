/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:59:18 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/08 18:04:59 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_list	a;
	t_list	el;
	t_list	b;

	if (argc < 2)
		return (0);
	a = ft_lstnew(1);
	el = ft_lstnew(2);
	ft_lstadd_back(&a, el);	
	


	return (0);
}
