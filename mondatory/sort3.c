/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:36:21 by matef             #+#    #+#             */
/*   Updated: 2022/07/05 15:18:43 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(int *a, int *b, int top_a, int top_b)
{
	ft_putstr("rrr\n");
	rra(a, top_a);
	rrb(b, top_b);
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

void	if_av_has_alpha(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (has_alpha(av[i]))
			my_exit("Error\n");
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
			my_exit("Error\n");
		}
		tmp[i] = (int)ft_atoi(tab[i]);
		i++;
	}
}

void	sort_stack(t_node *node, int ac)
{
	if (ac == 4)
	{
		random_3nbr(node);
	}
	else
	{
		if (ac == 6)
			random_5nbr(node);
		else
		{
			push_sorted_to_b(node);
			push_sorted_to_a(node);
		}
	}
}
