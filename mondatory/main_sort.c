#include "../push_swap.h"

void    push_sorted_to_b(t_node *vars)
{
    int chunk;
    int i;
    chunk = (vars->top_a / 10) + 10;

    i = 0;
    while (0 <= vars->top_a)
    {

        if (vars->a[i++] < chunk)
            pb(vars->a, vars->b, vars->top_a, vars->top_b);

        vars->top_a--;
        vars->top_b++;
    }

}