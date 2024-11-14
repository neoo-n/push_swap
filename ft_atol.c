/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:13:30 by dvauthey          #+#    #+#             */
/*   Updated: 2024/11/13 13:46:34 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_ismin(const char *str)
{
	char	*max;

	max = "-9223372036854775808";
	if (str == max)
		return (1);
	return (0);
}

long long	ft_atol(const char *str)
{
	int			i;
	long long	result;
	int			isneg;

	i = 0;
	result = 0;
	isneg = 1;
	if (ft_ismin(str))
		return (-9223372036854775807LL - 1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			isneg = -1;
		i++;
	}	
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * isneg);
}
