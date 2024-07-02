/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:42:25 by aohssine          #+#    #+#             */
/*   Updated: 2024/06/02 15:13:06 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **args)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		range;

	range = 15;
	stack_b = NULL;
	stack_a = fill_args(args);
	if (stack_a == NULL)
		return (put_message("Error\n", 2));
	if (is_sorted(stack_a) == 1)
	{
		free_stack(&stack_a);
		return ;
	}
	if (lstsize(stack_a) <= 5)
		mini_sorted(&stack_a, &stack_b);
	else
	{
		if (lstsize(stack_a) > 100)
			range = 35;
		sort_to_b(&stack_a, &stack_b, range);
		sort_to_a(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return ;
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (check_args(argc, argv) == -1)
		{
			put_message("Error\n", 2);
			return (0);
		}
		push_swap(argv);
	}
	return (0);
}

void	free_args(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
	return ;
}

void	free_stack(t_node **node)
{
	t_node	*tmp;

	if (*node == NULL)
		return ;
	tmp = NULL;
	while (*node != NULL)
	{
		tmp = (*node)->next;
		free(*node);
		*node = tmp;
	}
	return ;
}

int	is_sorted(t_node *stack)
{
	t_node	*curr;
	t_node	*next;

	curr = stack;
	next = stack->next;
	while (next != NULL)
	{
		if (curr->data > next->data)
			return (0);
		curr = curr->next;
		next = next->next;
	}
	return (1);
}
