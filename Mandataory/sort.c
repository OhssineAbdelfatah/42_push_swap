/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:46:07 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/31 19:04:15 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_nbr(t_node **head)
{
	if ((*head)->data > (*head)->next->data
		&& (*head)->data > (*head)->next->next->data)
	{
		ra_rb(head, 'a');
		if ((*head)->data > (*head)->next->data)
			sa_sb(head, 'a');
	}
	else if ((*head)->next->data > (*head)->next->next->data
		&& (*head)->next->data > (*head)->data)
	{
		rra_rrb(head, 'a');
		if ((*head)->data > (*head)->next->data)
			sa_sb(head, 'a');
	}
	else if ((*head)->next->next->data > (*head)->data
		&& (*head)->next->next->data > (*head)->next->data)
	{
		if ((*head)->data > (*head)->next->data)
			sa_sb(head, 'a');
	}
}

void	sort_4_nbr(t_node **stack_a, t_node **stack_b)
{
	find_min_pb(stack_a, stack_b);
	sort_3_nbr(stack_a);
	pa_pb(stack_b, stack_a, 'a');
}

void	sort_5_nbr(t_node **stack_a, t_node **stack_b)
{
	find_min_pb(stack_a, stack_b);
	find_min_pb(stack_a, stack_b);
	sort_3_nbr(stack_a);
	pa_pb(stack_b, stack_a, 'a');
	pa_pb(stack_b, stack_a, 'a');
}
