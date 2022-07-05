/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bouns_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:31:27 by matef             #+#    #+#             */
/*   Updated: 2022/07/05 15:18:02 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
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

void	if_av_has_alpha(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (has_alpha_2(av[i]))
			my_exit("Error\n");
		i++;
	}
}
