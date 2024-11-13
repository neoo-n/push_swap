/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:56:47 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/13 11:48:01 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/src/libft.h"

typedef struct s_dbllist
{
	int					number;
	int					index;
	struct s_dbllist	*previous;
	struct s_dbllist	*next;
}						t_dbllist;

long long	ft_atol(const char *str);
t_dbllist	*fct_sab(t_dbllist **a);
void		fct_ss(t_dbllist *a, t_dbllist *b);
t_dbllist	*fct_pab(t_dbllist *a, t_dbllist *b);
int			ft_dbllstsize(t_dbllist *lst);
t_dbllist	*ft_dbllstnew(int content);
void		ft_dbllstadd_back(t_dbllist **lst, t_dbllist *new);
void		ft_putdbllst(t_dbllist *lst);
void		fct_notvalid();
void		fct_isnumber(char *s);
t_dbllist	*check_arg2(char *av, t_dbllist **a);
t_dbllist	*check_argm2(int len, char **argv, t_dbllist **a);

#endif