/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:37:32 by matef             #+#    #+#             */
/*   Updated: 2022/07/04 17:00:38 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
