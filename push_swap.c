/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:38:14 by matef             #+#    #+#             */
/*   Updated: 2022/07/05 19:10:40 by matef            ###   ########.fr       */
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
				my_exit("Error\n");
			j++;
		}
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
	if (check_if_sort(node->a, *node->top_a))
		return (0);
	sort_stack(node, ac);
	return (0);
}
