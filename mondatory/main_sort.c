#include "../push_swap.h"

void    push_sorted_to_b(t_node *vars)
{
    int chunk;
    int counter;
    int n;

    n = 1;
    counter = 0;
    chunk = (*vars->top_a / 10) + 10;

    //printf("%d", chunk);
    while (0 <= *vars->top_a)
    {

        if (vars->a[*vars->top_a] < chunk * n)
        {
            pb(vars->a, vars->b, vars->top_a, vars->top_b);
            if (vars->b[*vars->top_b] < (n * chunk) - (chunk / 2))
				rb(vars->b, *vars->top_b, '1');
            counter++;
        }
        else
        {
            ra(vars->a, *vars->top_a, '1');
        }

        if (counter == chunk * n)
			n++;
        //*vars->top_a--;
        //*vars->top_b++;
    }

}

int	find_j(int *t, int top, int j)
{
	int	i;

	i = 0;
	while (i <= top)
	{
		if (j == t[i])
			return (i);
		i++;
	}
	return (-1);
}

void	mini_boucle_sorta(t_node *var, int max)
{
	int	j_index;
    int i;

    i = 0;
	j_index = -1;
	while (i <= *var->top_b)
	{
		j_index = find_j(var->b, *var->top_b, max);
		if (j_index >= (*var->top_b / 2))
		{
			if (var->b[*var->top_b] != max)
				rb(var->b, *var->top_b, '1');
		}
		if (j_index < (*var->top_b / 2))
		{
			if (var->b[*var->top_b] != max)
				rrb(var->b, *var->top_b);
		}
		i++;
	}
}

void	push_sorted_to_a(t_node *var)
{
	int	i;
	int	tb;
	int	max;

	i = 0;
	tb = *var->top_b;
	max = var->b[tb];
	while (tb + 1)
	{
		i = 0;
		while (i <= *var->top_b)
		{
			if (max < var->b[i])
				max = var->b[i];
			i++;
		}

        //printf("max = %d \n", max);
		mini_boucle_sorta(var, max);
		pa(var->a, var->b, var->top_a, var->top_b);
		max = var->b[*var->top_b];
		tb--;
	}
}

/*
void    push_sorted_to_a1(t_node *vars)
{

}*/