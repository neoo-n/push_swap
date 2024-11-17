/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:56:47 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/17 16:48:12 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/src/libft.h"

typedef struct s_dbllist
{
	int					number;
	int					index;
	struct s_dbllist	*prev;
	struct s_dbllist	*next;
}						t_dbllist;

void		fct_sab(t_dbllist **a);
void		fct_ss(t_dbllist **a, t_dbllist **b);
void		fct_pab(t_dbllist **a, t_dbllist **b);
void		fct_rab(t_dbllist **a);
void		fct_rr(t_dbllist **a, t_dbllist **b);
void		fct_rrab(t_dbllist **a);
void		fct_rrr(t_dbllist **a, t_dbllist **b);
int			ft_dbllstsize(t_dbllist *lst);
t_dbllist	*ft_dbllstnew(int content);
void		ft_dbllstadd_back(t_dbllist **lst, t_dbllist *new);
void		ft_dbllstadd_front(t_dbllist **lst, t_dbllist *new);
void		ft_putdbllst(t_dbllist *lst);
t_dbllist	*ft_dbllstlast(t_dbllist **lst);
void		notvalid();
void		isnumber(char *s);
void		is_alreadyin(t_dbllist **a, int n);
t_dbllist	*check_arg2(char *av, t_dbllist **a);
void		check_argm2(int len, char **argv, t_dbllist **a);
void		ft_push_swap(t_dbllist *a);

#endif