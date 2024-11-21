/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:56:47 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/21 10:40:20 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void		optocall(char *op, char *letter, t_dbllist **a, t_dbllist **b);
int			ft_dbllstsize(t_dbllist *lst);
t_dbllist	*ft_dbllstnew(int content);
void		ft_dbllstadd_back(t_dbllist **lst, t_dbllist *new);
t_dbllist	*ft_dbllstlast(t_dbllist *lst);
void		ft_dbllstclear(t_dbllist **lst);
void		ft_putdbllst(t_dbllist *lst);
t_dbllist	*ft_dbllstcpy(t_dbllist *a);
void		notvalid();
void		isnumber(char *s);
void		is_alreadyin(t_dbllist **a, int n);
t_dbllist	*check_arg2(char *av, t_dbllist **a);
void		check_argm2(int len, char **argv, t_dbllist **a);
int			placeinb(t_dbllist *b, t_dbllist *a, int i);
int			indextoorder(t_dbllist *a, t_dbllist *b);
void		simple_rotating(t_dbllist **a, t_dbllist **b, int *indexl, char *s);
void		rot_decrease(t_dbllist **b);
void		double_samerotating(t_dbllist **a, t_dbllist **b, int *indexa, int *indexb);
void		ft_push_swap(t_dbllist *a);

#endif