#include"push_swap.h"

void sort_3_nbr(t_node **head)
{
    if( (*head)->data > (*head)->next->data )
        sa(head);
    if( (*head)->next->data > (*head)->next->next->data )
    {
        rra(head);
        sa(head);
    }
    if( (*head)->data > (*head)->next->data )
        sa(head);
}

void find_min_pb(t_node **stack_a, t_node **stack_b)
{
    t_node *tmp;
    int min;
    int i_min;
    int flag;
    
    flag = lstsize(*stack_a);
    i_min = 0;
    min = (*stack_a)->data   ;


    tmp = *stack_a;
    while(tmp != NULL)
    {
        if(min > tmp->data)
            min =  tmp->data;
        tmp = tmp->next;
    } 

    tmp = *stack_a;
    while(tmp != NULL)
    {
        if(min == tmp->data)
            break;
        i_min++;
        tmp = tmp->next;
    } 
    ft_printf("-------{%d} \n",flag);
    if(i_min == 0)
        pb(stack_a, stack_b);
    else if(i_min == 4 ){
        rra(stack_a);
        pb(stack_a, stack_b);
    }else if(i_min == 3 && flag == 5){
        rra(stack_a);
        rra(stack_a);
        pb(stack_a, stack_b);
    }else if(i_min == 3 && flag == 4){
        rra(stack_a);
        pb(stack_a, stack_b);
    }else if( i_min == 2){
        ra(stack_a);
        ra(stack_a);
        pb(stack_a, stack_b);
    }else if ( i_min == 1){
        ra(stack_a);
        pb(stack_a, stack_b);
    }
    
}
void sort_5_nbr(t_node **stack_a, t_node **stack_b)
{
    t_node *tmp;
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
    pa(stack_b, stack_a);
    pa(stack_b, stack_a);
}
