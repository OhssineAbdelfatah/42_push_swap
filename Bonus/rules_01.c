/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:33:15 by aohssine          #+#    #+#             */
/*   Updated: 2024/06/02 09:33:16 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa_sb(t_node **stack)
{
	t_node	*tmp;

	if (stack == NULL || *stack == NULL || lstsize(*stack) < 2)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	return ;
}

void	pa_pb(t_node **base, t_node **target)
{
	t_node	*node_b;

	if (base == NULL || *base == NULL)
		return ;
	node_b = *base;
	*base = (*base)->next;
	node_b->next = *target;
	*target = node_b;
	return ;
}

void	ra_rb(t_node **stack)
{
	t_node	*last;
	t_node	*tmp;

	if (*stack == NULL || (*stack)->next == NULL || lstsize(*stack) < 2)
		return ;
	tmp = (*stack);
	*stack = (*stack)->next;
	tmp->next = NULL;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	return ;
}

void	rra_rrb(t_node **stack)
{
	t_node	*tmp;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL || lstsize(*stack) < 2)
		return ;
	tmp = (*stack)->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	if (last != NULL)
		last->next = *stack;
	*stack = last;
	return ;
}
