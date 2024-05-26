#include"push_swap.h"

void sort_3_nbr(t_node **head)
{
    if(lstsize(*head) != 3)
        return ;
    if( (*head)->data > (*head)->next->data )
        sa_sb(head, 'a');
    if( (*head)->next->data > (*head)->next->next->data )
    {
        rra_rrb(head,'a');
        sa_sb(head, 'a');
    }
    if( (*head)->data > (*head)->next->data )
        sa_sb(head,'a');
}

void find_min_pb(t_node **stack_a, t_node **stack_b)
{
    t_node *tmp;
    int min;
    int indice;
    int i;
    bool side;
    
    i = 0;
    indice = 0;
    side = false;
    min = (*stack_a)->data;
    tmp = (*stack_a)->next;
    while (tmp != NULL)
    {
        if(tmp->data < min){
            min = tmp->data ;
            indice = i;
        }   
        i++;
        tmp = tmp->next;
    }
    if(indice > lstsize(*stack_a)/2)
    {
        indice = lstsize(*stack_a)/2 - indice ;
        side = true;
    }
    while(indice-- > 0)
    {
        if(side)
            rra_rrb(stack_a, 'a');
        else
            ra_rb(stack_a, 'a');
    }
    pa_pb(stack_a, stack_b, 'b');
    return ;
}
void sort_5_nbr(t_node **stack_a, t_node **stack_b)
{
    t_node *tmp;
    find_min_pb(stack_a,stack_b);
    find_min_pb(stack_a,stack_b);
       // print satck a
    tmp = *stack_a;
    ft_printf("stack_a \n");
    while(tmp != NULL){
        ft_printf(" %d ",tmp->data);
        tmp = tmp->next;
    }

    find_min_pb(stack_a,stack_b);
    tmp = *stack_a;
    ft_printf("stack_a \n");
    while(tmp != NULL){
        ft_printf(" %d ",tmp->data);
        tmp = tmp->next;
    }
    sort_3_nbr(stack_a);
    pa_pb(stack_b, stack_a, 'a');
    pa_pb(stack_b, stack_a, 'a');
}
