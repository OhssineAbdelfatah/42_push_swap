#include"push_swap.h"

void sa_sb(t_node **stack, char status)
{
    if(status == 'a')
        ft_printf("sa\n");
    else if (status == 'b')
        ft_printf("sb\n");
    if(stack == NULL )
        return ;
    t_node *tmp;
    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next = *stack;
    *stack = tmp;
    return ;
}

void pa_pb(t_node **base, t_node **target,char status)
{
    if(status == 'a')
        ft_printf("pa\n");
    else if (status == 'b')
        ft_printf("pb\n");
    t_node *node_b;
    
    if(*base == NULL)
        return ;
    node_b = *base;
    *base = (*base)->next;
    node_b->next = *target;
    *target = node_b;
    return ;
}

void ra_rb(t_node **stack, char status)
{
    if(status == 'a')
        ft_printf("ra\n");
    else if (status == 'b')
        ft_printf("rb\n");
    t_node *tmp;
    t_node *last;

    if(*stack == NULL || (*stack)->next == NULL )
        return ;
    tmp = (*stack);
    *stack = (*stack)->next; 
    tmp->next = NULL;
    last = *stack;
    while(last->next != NULL)
        last = last->next;
    last->next = tmp;
    return;
}

void rra_rrb(t_node **stack, char status)
{

    t_node *tmp;
    t_node *last;

    if(status == 'a')
        ft_printf("rra\n");
    else if (status == 'b')
        ft_printf("rrb\n");
    if(*stack == NULL || (*stack)->next == NULL)
        return ;
    tmp = (*stack)->next;
    while(tmp->next->next != NULL)
        tmp= tmp->next;
    last = tmp->next;
    tmp->next = NULL;
    last->next = *stack;
    *stack = last;
    return;
}
