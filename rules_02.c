#include"push_swap.h"

void ss(t_node *stack_a, t_node *stack_b)
{
    ft_printf("ss\n");
    if(stack_b == NULL && stack_a == NULL)
        return ;
    sa_sb(&stack_a,'0');
    sa_sb(&stack_b,'0');
    return ;
}

void rr(t_node **stack_a, t_node **stack_b)
{
    ft_printf("rr\n");
    if(stack_a != NULL && *stack_a != NULL)
        ra_rb(stack_a, '0');
    if(stack_b != NULL && *stack_b != NULL)
        ra_rb(stack_b, '0');
    return ;
}
void rrr(t_node **stack_a, t_node **stack_b)
{
    ft_printf("rrr\n");
    if( stack_a != NULL && *stack_a != NULL)
        rra_rrb(stack_a, '0');
    if( stack_b != NULL && *stack_b != NULL )
        rra_rrb(stack_b, '0');
    return ;
}