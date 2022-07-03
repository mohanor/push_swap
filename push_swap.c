/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:38:14 by matef             #+#    #+#             */
/*   Updated: 2022/07/03 22:40:18 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_alpha(char *str)
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

void	my_exit(char *str)
{
	ft_putstr(str);
	exit(0);
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

void	inverse_tab(t_node *node, int ac)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = ac - 2;
	while (i <= j)
	{
		tmp = node->a[i];
		node->a[i] = node->a[j];
		node->a[j] = tmp;
		i++;
		j--;
	}
}

void	if_av_has_alpha(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (has_alpha(av[i]))
			my_exit("error2\n");
		i++;
	}
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



int	main(int ac, char **av)
{
	int		i;
	t_node	*node;
	int		la;
	int		lb;

	la = ac - 2;
	lb = -1;
	if (ac == 2)
		return (0);
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	parcing(node, av, ac);
	node->b = (int *)malloc(sizeof(int) * ac - 1);
	if (!node->b)
		return (0);
	i = 0;
	while (i < ac - 1)
		node->b[i++] = -1;
	node->top_a = &la;
	node->top_b = &lb;
	if (ac == 4)
		random_3nbr(node);
	else if (ac == 6)
		random_5nbr(node);
	else
	{
		push_sorted_to_b(node);
		push_sorted_to_a(node);
	}
	return (0);
}
