/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bouns_sort1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:28:35 by matef             #+#    #+#             */
/*   Updated: 2022/07/04 23:41:35 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(int *tab, int len)
{
	int	tmp;

	tmp = tab[len - 1];
	tab[len - 1] = tab[len - 2];
	tab[len - 2] = tmp;
}

void	sb(int *b, int len)
{
	int	tmp;

	tmp = b[len - 1];
	b[len - 1] = b[len - 2];
	b[len - 2] = tmp;
}

void	ss(int *a, int *b, int top_a, int top_b)
{
	sa(a, top_a + 1);
	sb(b, top_b + 1);
}

void	pa(int *a, int *b, int *top_a, int *top_b)
{
	a[*top_a + 1] = b[*top_b];
	*top_b -= 1;
	*top_a += 1;
}

void	pb(int *a, int *b, int *top_a, int *top_b)
{
	if (*top_a > -1)
	{
		b[*top_b + 1] = a[*top_a];
		*top_b += 1;
		*top_a -= 1;
	}
}
