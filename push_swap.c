#include "push_swap.h"

t_node *creat_node(int num){
    t_node *node;

    node = (t_node*)malloc(sizeof(t_node));
    if(!node)
        throw_error("node allocation failed.");
    node->data = num;
    node->side_a = false;
    node->side_b = false;
    node->next = NULL;
    node->move = 0;
    node->ind_a = INT32_MAX;
    node->ind_b = INT32_MAX;
    return node;
}

void add_to_stack(t_node *node, t_node **head){
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

void push_swap(char **args)
{
    t_node *stack_a ;
    t_node *stack_b ;
    // t_node *best_node;
    int best_move;

    stack_a = fill_args(args);
    if(stack_a == NULL)
        return ;
    stack_b = NULL;

    // pb(&stack_a, &stack_b);
    // pb(&stack_a, &stack_b);

    while(stack_a != NULL)
    {
        // stack_a = count_move_a(stack_a);
        stack_a = count_move_b(stack_b, stack_a);
        // best_move = INT32_MAX;
        // tmp_a = stack_a;

       /*  while(tmp_a != NULL)
        {   
            if(tmp_a->move < best_move)
            {
                best_move = tmp_a->move;
                best_node = tmp_a;
            }
            tmp_a = tmp_a->next;
        } */

        // ft_printf("node %d , move %d\n",best_node->data, best_move);
        // find best node in a , set it in head

/*         if(best_node->side_a)
        {   
            best_move = best_node->ind_a - lstsize(stack_a);
            while(best_move-- > 0)
                rra(&stack_a);
        }
        else
        {
            best_move = best_node->ind_a;
            while(best_move-- > 0)
                ra(&stack_a);
        } */
        

        best_move = stack_a->move;
        ft_printf("best {%d} \n",best_move );
        while(best_move-- > 0){
            if(stack_a->side_b)
                rrb(&stack_b);
            else
                rb(&stack_b);
        }
  
        // set up stack b , to best position to push node from a

        pb(&stack_a, &stack_b);
        // tmp_a = tmp_a->next;
    }
    
    // now we should cunt moves in a and b
    // to chose the best node to be pushed

 /*    sort_stack_b(&stack_a, &stack_b); */

    // operate over stack b till it is Descending order head: max >>> min 

    /* int max_b_ind = find_max_indice(stack_b);
    if(max_b_ind > lstsize(stack_b))
    {   
        max_b_ind = lstsize(stack_b) - max_b_ind;
        while(max_b_ind-- > 0)
            rrb(&stack_b);
    }else{
        while(max_b_ind-- > 0)
            rb(&stack_b);
    } */

    // push back all sorted elements to a
    /* while(stack_b != NULL){
        pa(&stack_b, &stack_a);
    } */

    print(stack_a, stack_b);
    // free all allocaated nodes
    /*  free_stack(stack_a); */

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

void print(t_node *stack_a, t_node *stack_b)
{
   ft_printf("\n");
    t_node *tmp = stack_a;
    t_node *tmp1 = stack_b;
    ft_printf("stack a :\n head \t");
    while(tmp != NULL){
        ft_printf("%d \t",tmp->data, tmp->move);
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