/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:45:43 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/30 19:46:58 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_node **stack, char status)
{
	t_node	*tmp;

	if (stack == NULL || *stack == NULL)
		return ;
	if (status == 'a')
		put_message("sa\n", 1);
	else if (status == 'b')
		put_message("sb\n", 1);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	return ;
}

void	pa_pb(t_node **base, t_node **target, char status)
{
	t_node	*node_b;

	if (*base == NULL || base == NULL)
		return ;
	if (status == 'a')
		put_message("pa\n", 1);
	else if (status == 'b')
		put_message("pb\n", 1);
	node_b = *base;
	*base = (*base)->next;
	node_b->next = *target;
	*target = node_b;
	return ;
}

void	ra_rb(t_node **stack, char status)
{
	t_node	*last;
	t_node	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	if (status == 'a')
		put_message("ra\n", 1);
	else if (status == 'b')
		put_message("rb\n", 1);
	tmp = (*stack);
	*stack = (*stack)->next;
	tmp->next = NULL;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	return ;
}

void	rra_rrb(t_node **stack, char status)
{
	t_node	*tmp;
	t_node	*last;

	if (status == 'a')
		put_message("rra\n", 1);
	else if (status == 'b')
		put_message("rrb\n", 1);
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack;
	*stack = last;
	return ;
}
