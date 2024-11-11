/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:05:27 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/11 10:58:37 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*fct_sab(int *a)
{
	int	len;
	int	temp;

	len = ft_(a);
	if (len < 2)
		return (a);
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	return (temp);
}

void	fct_ss(int *a, int *b)
{
	fct_sab(a);
	fct_sab(b);
}
