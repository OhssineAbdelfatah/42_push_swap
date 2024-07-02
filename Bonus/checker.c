/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:33:36 by aohssine          #+#    #+#             */
/*   Updated: 2024/06/02 15:13:58 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker(char **args)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	stack_a = fill_args(args);
	if (stack_a == NULL)
		return (put_message("Error\n", 2));
	if (execute_rule(&stack_a, &stack_b) == -1)
	{
		put_message("Error\n", 2);
		free_stack(&stack_b);
		free_stack(&stack_a);
		return ;
	}
	if (is_sorted(stack_a) && stack_b == NULL)
		put_message("OK\n", 1);
	else
		put_message("KO\n", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
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
		checker(argv);
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

	if (stack == NULL)
		return (0);
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
