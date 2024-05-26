#include"push_swap.h"

void push_min_to_b(t_node **stack_a,t_node **stack_b)
{
    while(lstsize(*stack_a) > 3)
    {
        //this if should contain push to best move
        if((*stack_a)->data < count_avrg(*stack_a))
            pa_pb(stack_a, stack_b, 'a');
        else
            ra_rb(stack_a, 'a');
    }
    return ;
}

int count_avrg(t_node *stack)
{
	int avrg;
	int size ;

	size = lstsize(stack);
	if(stack == NULL || size == 0)
		return 0;
	avrg = 0;
	while (stack != NULL)
	{
		avrg = avrg + stack->data;
		stack = stack->next;
	}
	avrg =(int)(avrg / size);
	return avrg;
}

