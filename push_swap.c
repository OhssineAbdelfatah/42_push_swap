#include "push_swap.h"

t_node *creat_node(int num)
{
    t_node *node;

    node = (t_node*)malloc(sizeof(t_node));
    if(!node)
        throw_error("node allocation failed.");
    node->data = num;
    node->side = false;
    node->next = NULL;
    node->move = 0;
    node->ind = 0;
    return node;
}

void set_stack_to_zero(t_node **stack)
{
    t_node *tmp;

    if(*stack == NULL)
        return ;
    tmp = *stack;
    while(tmp != NULL){
        tmp->ind = 0;
        tmp->move = 0;
        tmp->side = false;
        tmp = tmp->next ;
    }
    return ;
}

void add_to_stack(t_node *node, t_node **head)
{
    t_node *tmp;

    if(*head == NULL){
        *head = node;
        return ;
    }
    tmp = *head;
    while(tmp->next != NULL)
        tmp = tmp->next;
    
    tmp->next = node;
    return ;
}

void print(t_node *stack_a, t_node *stack_b)
{
   ft_printf("\n");
    t_node *tmp = stack_a;
    t_node *tmp1 = stack_b;
    ft_printf("stack a :\n head \t");
    while(tmp != NULL){
        ft_printf("%d \t",tmp->data);
        tmp = tmp->next;
    }
    ft_printf("\n----------------------\n");
    /*stack a*/

    /*stack b*/
    ft_printf("stack b :\n head \t");
    while(tmp1 != NULL){
        ft_printf("%d \t",tmp1->data);
        tmp1 = tmp1->next;
    }
    ft_printf("\n----------------------\n");
}

void push_swap(char **args)
{
    t_node *stack_a ;
    t_node *stack_b ;
    int best_move;

    stack_a = fill_args(args);
    if(stack_a == NULL)
        return ;
    stack_b = NULL;

    while(lstsize(stack_a) > 3)
    {
        set_stack_to_zero(&stack_a);
        set_stack_to_zero(&stack_b);
        stack_a->ind = count_move(stack_b, stack_a->data);
        if(stack_a->ind == -1)
            stack_a->ind = find_max_indice(stack_b);
        if(stack_a->ind > lstsize(stack_b)/2 )
        {
            stack_a->side = true;
            stack_a->move = lstsize(stack_b) - stack_a->ind ;
        }
        else
            stack_a->move =  stack_a->ind ;
        best_move = stack_a->move;
        while(best_move-- > 0)
        {
            if( stack_a->side )
                rra_rrb(&stack_b, 'b');
            else
                ra_rb(&stack_b,'b');
        }
        pa_pb(&stack_a, &stack_b,'b');
    }

    sort_3_nbr(&stack_a);

    while(stack_b != NULL)
    {
        set_stack_to_zero(&stack_a);
        set_stack_to_zero(&stack_b);
        stack_b->ind = count_move_a(stack_a, stack_b->data);
        if(stack_b->ind == -1)
                stack_b->ind = find_min(stack_a);
        if(stack_b->ind > lstsize(stack_a)/2 )
        {
            stack_b->side = true;
            stack_b->move = lstsize(stack_a) - stack_b->ind ;
        }
        else
            stack_b->move =  stack_b->ind ;
        best_move = stack_b->move;
        while(best_move-- > 0)
        {
            if( stack_b->side )
                rra_rrb(&stack_a, 'a');
            else
                ra_rb(&stack_a, 'a');
        }
        pa_pb(&stack_b, &stack_a,'a');

    }

    best_move = find_min(stack_a);
    if(best_move > lstsize(stack_a)/2 ){
        best_move = lstsize(stack_a) - best_move;
        while(best_move-- > 0)
            rra_rrb(&stack_a,'a');
    }else{
        while(best_move-- > 0)
            ra_rb(&stack_a,'a');
    }
    // free all allocaated nodes
    free_stack(stack_a);

    return ;
}

int main(int argc, char **argv){
    if(argc >= 2){
        if(check_args(argc, argv) == -1){
            ft_putstr_fd("check args : ERROR.\n",2);
            return 0;
        }
        // else
        //     ft_putstr_fd("check args : OK.\n",1);
        push_swap(argv);
    }else
        ft_printf("error too few args.\n");
    // system("leaks push_swap");
        
}

