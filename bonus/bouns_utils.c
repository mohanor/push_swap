/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bouns_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:40:47 by matef             #+#    #+#             */
/*   Updated: 2022/07/04 23:07:19 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*str;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return ((char *)str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = ' ';
	}
	if (!s2)
		return (NULL);
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	while (s1[++i])
		p[i] = s1[i];
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}

void	my_exit(char *str)
{
	ft_putstr(str);
	exit(0);
}

void	put_to_tmp(char **tab, int *tmp)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!not_long(tab[i]))
		{
			free(tab);
			free(tmp);
			my_exit("error\n");
		}
		tmp[i] = (int)ft_atoi(tab[i]);
		i++;
	}
}

int	*tab_index(int *tab, int len)
{
	int	*arr;
	int	i;
	int	j;
	int	index;

	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	i = 0;
	while (i < len)
	{
		j = 0;
		index = 0;
		while (j < len)
		{
			if (tab[i] > tab[j])
				index++;
			j++;
		}
		arr[i] = index;
		i++;
	}
	free(tab);
	return (arr);
}

void	if_has_deplcate(int *tmp, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 2)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (tmp[i] == tmp[j])
				my_exit("error\n");
			j++;
		}
		i++;
	}
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
			my_exit("error\n");
		i++;
	}
}

void	inverse_tab(t_node *node, int ac)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = ac - 2;
	while (i < j)
	{
		tmp = node->a[i];
		node->a[i] = node->a[j];
		node->a[j] = tmp;
		i++;
		j--;
	}
}

int	has_alpha_2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((int)s1[i] - (int)s2[i]);
}
