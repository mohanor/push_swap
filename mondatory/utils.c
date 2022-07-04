/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:58:33 by matef             #+#    #+#             */
/*   Updated: 2022/07/04 16:49:24 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *p)
{
	int	i;

	i = 0;
	if (!p)
		return (0);
	while (p[i])
		i++;
	return (i);
}

int	ft_nbrlen(long long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

long long	ft_atoi(char *str)
{
	int			i;
	long long	r;
	long long	k;

	i = 0;
	r = 0;
	k = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			k *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + ((long long)str[i] - 48);
		i++;
	}
	return (r * k);
}

int	not_long(char *str)
{
	long long	nb;
	long long	nb_max;
	long long	nb_min;

	nb_max = INT32_MAX;
	nb_min = INT32_MIN;
	nb = ft_atoi(str);
	if (ft_nbrlen(nb) == ft_strlen(str))
	{
		if (nb >= nb_min && nb <= nb_max)
			return (1);
	}
	return (0);
}
