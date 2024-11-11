/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:56:47 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/11 18:42:18 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/src/libft.h"

typedef struct s_dbllist
{
	int		number;
	int		index;
	t_list	*previous;
	t_list	*next;
}			t_dbllist;

int	*fct_sab(t_dbllist **a);
void	fct_ss(t_dbllist *a, t_dbllist *b);
int	*fct_pab(t_dbllist *a, t_dbllist *b);
int	ft_dbllstsize(t_dbllist *lst);


#endif