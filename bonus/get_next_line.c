/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:41:36 by matef             #+#    #+#             */
/*   Updated: 2022/07/04 23:50:22 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*get_next_line(int fd)
{
	int		i;
	char	*buff;
	char	*str;

	str = ft_strdup("");
	i = 0;
	buff = malloc(sizeof(char));
	if (!buff)
		return (0);
	i += read(fd, buff, 1);
	while (buff[0] && buff[0] != '\n' && i)
	{
		if (i == -1)
		{
			free(buff);
			return (0);
		}
		buff[i] = '\0';
		str = ft_strjoin(str, buff);
		i += read(fd, buff, 1);
	}
	free(buff);
	return (str);
}

void	parcing(t_node *node, char **av, int ac)
{
	int		i;
	char	*ptr;
	char	**tab;
	int		*tmp;

	if (ac < 2)
		my_exit("error1\n");
	if_av_has_alpha(av);
	i = 1;
	ptr = NULL;
	while (av[i])
	{
		ptr = ft_strjoin(ptr, av[i]);
		ptr = ft_strjoin(ptr, " ");
		i++;
	}
	tab = ft_split(ptr, ' ');
	tmp = (int *)malloc((ac - 1) * sizeof(int));
	if (!tmp)
		exit (1);
	put_to_tmp(tab, tmp);
	if_has_deplcate(tmp, ac);
	node->a = tab_index(tmp, ac -1);
	inverse_tab(node, ac);
}

int	check(t_node *vars, char *j)
{
	if (ft_strcmp(j, "ra") == 0)
		ra(vars->a, *vars->top_a);
	else if (ft_strcmp(j, "rb") == 0)
		rb(vars->b, *vars->top_b);
	else if (ft_strcmp(j, "rr") == 0)
		rr(vars->a, vars->b, *vars->top_a, *vars->top_b);
	else if (ft_strcmp(j, "sa") == 0)
		sa(vars->a, *vars->top_a + 1);
	else if (ft_strcmp(j, "sb") == 0)
		sb(vars->b, *vars->top_b + 1);
	else if (ft_strcmp(j, "ss") == 0)
		ss(vars->a, vars->b, *vars->top_a, *vars->top_b);
	else if (ft_strcmp(j, "rra") == 0)
		rra(vars->a, *vars->top_a);
	else if (ft_strcmp(j, "rrb") == 0)
		rrb(vars->b, *vars->top_b);
	else if (ft_strcmp(j, "rrr") == 0)
		rrr(vars->a, vars->b, *vars->top_a, *vars->top_b);
	else if (ft_strcmp(j, "pa") == 0)
		pa(vars->a, vars->b, vars->top_a, vars->top_a);
	else if (ft_strcmp(j, "pb") == 0)
		pb(vars->a, vars->b, vars->top_a, vars->top_b);
	else
	{
		write(1, "ko\n", 3);
		exit (1);
	}
	free(j);
	return (0);
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

void	checker(t_node *vars)
{
	char	*str;

	str = get_next_line(0);
	while (str[0])
	{
		//printf("00 %s\n", str);
		check(vars, str);
		str = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_node	*node;
	int		la;
	int		lb;
	int		i;

	if (ac == 2)
		return (0);
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	la = ac - 2;
	lb = -1;
	parcing(node, av, ac);
	node->b = (int *)malloc(sizeof(int) * ac - 1);
	if (!node->b)
		return (0);
	i = 0;
	while (i < ac - 1)
		node->b[i++] = -1;
	node->top_a = &la;
	node->top_b = &lb;
	checker(node);
	if (check_if_sort(node->a, *node->top_a))
		ft_putstr("ok\n");
	else
		ft_putstr("ko\n");
	return (0);
}
