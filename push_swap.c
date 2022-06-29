#include "push_swap.h"

int has_alpha(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
    
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!(str[i]>= '0' && str[i] <= '9'))
            return (1);
        i++;
    }
    return (0);
}

void my_exit(char *str)
{
    ft_putstr(str);
    exit(0);
}

int     not_long(char *str)
{
    long long nb;
    long long    nb_max;
    long long    nb_min;

    nb_max = INT32_MAX;
    nb_min = INT32_MIN;
    nb = ft_atoi(str);
    
    if (ft_nbrlen(nb) == ft_strlen(str))
    {
        if (nb >= nb_min && nb <= nb_max)
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    t_stack *tmp;
    t_stack *tmp_1;
    t_stack *tmp_2;
    int     i;
    //long long    nb;

    i = 1;
    if (ac < 2)
        return 0;

    while (av[i])
    {
        if (has_alpha(av[i]))
            my_exit ("error\n");
        if (!not_long(av[i]))
            my_exit ("error\n");
        i++;
    }

    // ft_putstr("ok");

    tmp = new_item((int)ft_atoi(av[1]));

    i = 2;
    while (av[i])
    {
        add_back(&tmp, new_item((int)ft_atoi(av[i])));
        i++;
    }

    int index;
    int elm;
    tmp_1 = tmp;
    while (tmp_1)
    {
        elm = tmp_1->value;
        tmp_2 = tmp;
        index = ac - 2;
        while (tmp_2)
        {
            if (elm < tmp_2->value)
                index--;
            
            tmp_2 = tmp_2->next;
        }
        printf("%d ", index);
        tmp_1 = tmp_1->next;
    }

    



    return (0);
}
