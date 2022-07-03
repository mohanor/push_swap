/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:41:21 by matef             #+#    #+#             */
/*   Updated: 2022/07/03 22:45:34 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int	*a;
	int	*b;
	int	*top_a;
	int	*top_b;
}	t_node;

int			ft_strlen(char *p);
void		ft_putstr(char *s);
void		ft_putchar(char c);
long long	ft_atoi(char *str);
int			ft_nbrlen(long long nb);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char *s, char c);
int			not_long(char *str);
void		sa(int *tab, int len, char c);
void		sb(int *b, int len, char c);
void		ss(int *a, int *b, int top_a, int top_b);
void		pa(int *a, int *b, int *top_a, int *top_b);
void		pb(int *a, int *b, int *top_a, int *top_b);
void		ra(int *a, int top_a, char c);
void		rb(int *b, int top_b, char c);
void		rr(int *a, int *b, int top_a, int top_b);
void		rra(int *a, int top_a);
void		rrb(int *b, int top_b);
void		rrr(int *a, int *b, int top_a, int top_b);
void		push_sorted_to_b(t_node *vars);
int			find_j(int *t, int top, int j);
void		mini_boucle_sorta(t_node *var, int j);
void		push_sorted_to_a(t_node *var);
void		random_5nbr(t_node *vars);
void		random_3nbr(t_node *vars);
int			find_min(int *a, int tb);
void		inverse_tab(t_node *node, int ac);

#endif