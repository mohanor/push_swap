#include "../push_swap.h"

t_stack    *new_item(int item)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->value = item;
    new->next = NULL;
    return (new);
}

void    add_back(t_stack **list, t_stack *new)
{
    t_stack *tmp;

    if (!list || !new)
        return ;
    if (*list)
    {
        tmp = *list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
    else
        *list = new;
}