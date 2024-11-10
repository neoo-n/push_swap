/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:05:27 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/08 18:15:56 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*fct_sa(int *a)
{
	int	len;
	t_stack	temp;

	len = ft_lstsize(a);
	if (len < 2)
		return (a);
	temp = (t_stack)ft_calloc(1, sizeof(t_stack));
	ft_lstadd_back(temp, a->next);
	ft_lstadd_back(temp, a);
	a = a->next;
	a = a->next;
	while (a)
	{
		ft_lstadd_back(temp, a);
		a = a->next;
	}
	free(a);
	return (temp);
}

int	*fct_sb(int *b)
{
	int	len;
	t_stack	temp;

	len = ft_lstsize(b);
	if (len < 2)
		return (b);
	temp = (t_stack)ft_calloc(1, sizeof(t_stack));
	ft_lstadd_back(temp, b->next);
	ft_lstadd_back(temp, b);
	b = b->next;
	b = b->next;
	while (b)
	{
		ft_lstadd_back(temp, b);
		b = b->next;
	}
	free(b);
	return (temp);
}

void	fct_ss(int *a, int *b)
{
	fct_sa(a);
	fct_sb(b);
}
