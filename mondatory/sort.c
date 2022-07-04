/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:28:35 by matef             #+#    #+#             */
/*   Updated: 2022/07/04 15:35:46 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(int *tab, int len, char c)
{
	int	tmp;

	if (c == '1')
		ft_putstr("sa\n");
	tmp = tab[len - 1];
	tab[len - 1] = tab[len - 2];
	tab[len - 2] = tmp;
}

void	sb(int *b, int len, char c)
{
	int	tmp;

	if (c == '1')
		ft_putstr("sb\n");
	tmp = b[len - 1];
	b[len - 1] = b[len - 2];
	b[len - 2] = tmp;
}

void	ss(int *a, int *b, int top_a, int top_b)
{
	ft_putstr("ss\n");
	sa(a, top_a + 1, '2');
	sb(b, top_b + 1, '2');
}

void	pa(int *a, int *b, int *top_a, int *top_b)
{
	ft_putstr("pa\n");
	a[*top_a + 1] = b[*top_b];
	*top_b -= 1;
	*top_a += 1;
}

void	pb(int *a, int *b, int *top_a, int *top_b)
{
	ft_putstr("pb\n");
	if (*top_a > -1)
	{
		b[*top_b + 1] = a[*top_a];
		*top_b += 1;
		*top_a -= 1;
	}
}
