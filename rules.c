#include"push_swap.h"

/*

sa (swap a): Swap the first 2 elements at the top of stack a.
    Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
    Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
    Do  nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
    Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
    The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
    The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
    The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
    The last element becomes the first one.
rrr : rra and rrb at the same time.

*/

void sa(t_node **stack_a){
    ft_printf("sa\n");
    if(stack_a == NULL )
        return ;
    t_node *tmp;
    tmp = (*stack_a)->next;
    (*stack_a)->next = tmp->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
    return ;
}

void sb(t_node **stack_b){
    ft_printf("sb\n");
    if(stack_b == NULL )
        return ;
    t_node *tmp;
    tmp = (*stack_b)->next;
    (*stack_b)->next = tmp->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
    return ;
}

void ss(t_node *stack_a, t_node *stack_b){
    ft_printf("ss\n");
    if(stack_b == NULL && stack_a == NULL)
        return ;
    sa(&stack_a);
    sb(&stack_b);
    return ;
}

void pb(t_node **stack_a, t_node **stack_b){
    ft_printf("pb\n");
    t_node *node_b;
    
    if(*stack_a == NULL)
        return ;
    node_b = *stack_a;
    *stack_a = (*stack_a)->next;
    node_b->next = *stack_b;
    *stack_b = node_b;
    return ;
}

void pa(t_node **stack_b, t_node **stack_a){
    ft_printf("pa\n");
    t_node *node_a;

    if(*stack_b == NULL)
        return ;
    node_a = *stack_b;
    *stack_b = (*stack_b)->next;
    node_a->next = *stack_a;
    *stack_a = node_a;
    return ;
}

void ra(t_node **stack_a){
    ft_printf("ra\n");
    t_node *tmp;
    t_node *last;

    if(*stack_a == NULL || (*stack_a)->next == NULL )
        return ;
    tmp = (*stack_a);
    *stack_a = (*stack_a)->next; 
    tmp->next = NULL;
    last = *stack_a;
    while(last->next != NULL)
        last = last->next;
    last->next = tmp;
    return;
}

void rb(t_node **stack_b){
    ft_printf("rb\n");
    t_node *tmp;
    t_node *last;

    if(*stack_b == NULL || (*stack_b)->next == NULL )
        return ;
    tmp = (*stack_b);
    *stack_b = (*stack_b)->next; 
    tmp->next = NULL;
    last = *stack_b;
    while(last->next != NULL)
        last = last->next;
    last->next = tmp;
    return;
}

void rr(t_node **stack_a, t_node **stack_b){
    ft_printf("rr\n");
    if(stack_a != NULL && *stack_a != NULL)
        ra(stack_a);
    if(stack_b != NULL && *stack_b != NULL)
        rb(stack_b);
    return ;
}

void rra(t_node **stack_a){
    ft_printf("rra\n");
    t_node *tmp;
    t_node *last;

    if(*stack_a == NULL || (*stack_a)->next == NULL)
        return ;
    tmp = (*stack_a)->next;
    while(tmp->next->next != NULL)
        tmp= tmp->next;
    last = tmp->next;
    tmp->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
    return;
}

void rrb(t_node **stack_b){
    ft_printf("rrb\n");
    t_node *tmp;
    t_node *last;

    if(*stack_b == NULL || (*stack_b)->next == NULL)
        return ;
    tmp = (*stack_b)->next;
    while(tmp->next->next != NULL)
        tmp= tmp->next;
    last = tmp->next;
    tmp->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    return;
}

void rrr(t_node **stack_a, t_node **stack_b){
    ft_printf("rrr\n");
    if( stack_a != NULL && *stack_a != NULL)
        rra(stack_a);
    if( stack_b != NULL && *stack_b != NULL )
        rrb(stack_b);
    return ;
}
