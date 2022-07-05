/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:27:22 by matef             #+#    #+#             */
/*   Updated: 2022/07/05 17:03:56 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(int *a, int tb)
{
	int	i;
	int	min;
	int	j;

	i = 0;
	min = a[0];
	j = 0;
	while (i <= tb)
	{
		if (a[i] < min)
		{
			min = a[i];
			j = i;
		}
		i++;
	}
	return (j);
}

void	random_3nbr(t_node *vars)
{
	if (vars->a[2] > vars->a[1])
	{
		if (vars->a[0] > vars->a[2])
			sa(vars->a, 2, '1');
		else if (vars->a[0] < vars->a[1])
		{
			sa(vars->a, *vars->top_a, '1');
			rra(vars->a, *vars->top_a);
		}
		else if (vars->a[0] < vars->a[2] && vars->a[0] > vars->a[1])
			ra(vars->a, *vars->top_a, '1');
	}
	else
	{
		if (vars->a[1] > vars->a[0] && vars->a[0] > vars->a[2])
		{
			sa(vars->a, *vars->top_a, '1');
			ra(vars->a, *vars->top_a, '1');
		}
		else if (vars->a[1] > vars->a[0] && vars->a[0] < vars->a[2])
			rra(vars->a, *vars->top_a);
	}
}

void	push_min_to_b(t_node *vars)
{
	int	i_min;

	i_min = find_min(vars->a, *vars->top_a);
	if (i_min == 2 || i_min == 3)
		ra(vars->a, *vars->top_a, '1');
	if (i_min == 2)
		ra(vars->a, *vars->top_a, '1');
	if (i_min == 1 || i_min == 0)
		rra(vars->a, *vars->top_a);
	if (i_min == 1)
		rra(vars->a, *vars->top_a);
	pb(vars->a, vars->b, vars->top_a, vars->top_b);
	i_min = find_min(vars->a, *vars->top_a);
	if (i_min == 2)
		ra(vars->a, *vars->top_a, '1');
	if (i_min == 1 || i_min == 0)
		rra(vars->a, *vars->top_a);
	if (i_min == 1)
		rra(vars->a, *vars->top_a);
	pb(vars->a, vars->b, vars->top_a, vars->top_b);
}

void	random_5nbr(t_node *vars)
{
	push_min_to_b(vars);
	random_3nbr(vars);
	if (vars->b[1] < vars->b[0])
		sb(vars->b, *vars->top_b + 1, '1');
	pa(vars->a, vars->b, vars->top_a, vars->top_b);
	if (vars->a[*vars->top_a - 1] < vars->a[*vars->top_a])
		ra(vars->a, *vars->top_a, '1');
	pa(vars->a, vars->b, vars->top_a, vars->top_b);
	if (vars->a[*vars->top_a - 1] < vars->a[*vars->top_a])
		ra(vars->a, *vars->top_a, '1');
}

int	check_if_sort(int *tab, int len)
{
	int	i;

	i = 0;
	while (i <= len - 1)
	{
		if (tab[i] < tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
