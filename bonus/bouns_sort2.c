/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bouns_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:32:30 by matef             #+#    #+#             */
/*   Updated: 2022/07/04 23:40:11 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(int *a, int top_a)
{
	int	i;
	int	p;

	p = a[top_a];
	i = 0;
	while (0 < top_a)
	{
		a[top_a] = a[top_a - 1];
		top_a--;
	}
	a[0] = p;
}

void	rb(int *b, int top_b)
{
	int	i;
	int	p;

	p = b[top_b];
	i = 0;
	while (0 < top_b)
	{
		b[top_b] = b[top_b - 1];
		top_b--;
	}
	b[0] = p;
}

void	rr(int *a, int *b, int top_a, int top_b)
{
	ra(a, top_a);
	rb(b, top_b);
}

void	rra(int *a, int top_a)
{
	int	i;
	int	p;

	p = a[0];
	i = 0;
	while (i <= top_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[top_a] = p;
}

void	rrb(int *b, int top_b)
{
	int	i;
	int	p;

	p = b[0];
	i = 0;
	while (i <= top_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[top_b] = p;
}
