/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:47:08 by aohssine          #+#    #+#             */
/*   Updated: 2024/06/01 09:44:16 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_to_stack(t_node *node, t_node **head)
{
	t_node	*tmp;

	if (node == NULL)
		return (-1);
	if (*head == NULL)
	{
		*head = node;
		return (0);
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	return (0);
}

void	find_min_pb(t_node **stack_a, t_node **stack_b)
{
	int	indice;

	indice = find_min(*stack_a);
	if (indice > lstsize(*stack_a) / 2)
	{
		indice = lstsize(*stack_a) - indice;
		while (indice-- > 0)
			rra_rrb(stack_a, 'a');
	}
	else
	{
		while (indice-- > 0)
			ra_rb(stack_a, 'a');
	}
	pa_pb(stack_a, stack_b, 'b');
	return ;
}

int	find_min(t_node *stack_a)
{
	int		min;
	int		indice;
	int		i;
	t_node	*tmp;

	i = 0;
	indice = 0;
	min = stack_a->data;
	tmp = stack_a;
	while (tmp != NULL)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			indice = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (indice);
}

int	find_max(t_node *stack)
{
	int		max;
	int		i;
	int		ind;
	t_node	*tmp;

	if (stack == NULL)
		return (0);
	i = 0;
	max = INT_MIN;
	ind = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->data > max)
		{
			max = tmp->data;
			ind = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (ind);
}

void	mini_sorted(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = lstsize(*stack_a);
	if (size == 5)
		sort_5_nbr(stack_a, stack_b);
	else if (size == 4)
		sort_4_nbr(stack_a, stack_b);
	else if (size == 3)
		sort_3_nbr(stack_a);
	else if (size == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa_sb(stack_a, 'a');
	}
}
