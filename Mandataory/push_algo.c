/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:46:23 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/31 14:00:46 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_b(t_node **stack_a, t_node **stack_b, int range)
{
	int	start;
	int	end;
	int	temp;

	start = 0;
	end = range - 1;
	sort_temp(stack_a);
	while (lstsize(*stack_a) >= 1)
	{
		if ((*stack_a)->ind <= end)
		{
			temp = (*stack_a)->ind;
			pa_pb(stack_a, stack_b, 'b');
			if (temp < start)
				ra_rb(stack_b, 'b');
			end++;
			start++;
		}
		else
			ra_rb(stack_a, 'a');
	}
	return ;
}

void	sort_temp(t_node **stack_a)
{
	int		*arr;
	t_node	*tmp;
	int		i;
	int		size;

	i = 0;
	size = lstsize(*stack_a);
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return ;
	tmp = *stack_a;
	while (tmp != NULL)
	{
		*(arr + i) = tmp->data;
		tmp = tmp->next;
		i++;
	}
	arr = bubble_sort(arr, lstsize(*stack_a));
	index_stack_a(stack_a, arr);
	free(arr);
	arr = NULL;
	return ;
}

void	index_stack_a(t_node **stack_a, int *sorted_stk)
{
	t_node	*tmp;
	int		i;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		i = 0;
		while (i < lstsize(*stack_a))
		{
			if (sorted_stk[i] == tmp->data)
				tmp->ind = i;
			i++;
		}
		tmp = tmp->next;
	}
	return ;
}

int	*bubble_sort(int *temp, int size)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (temp[i] > temp[j])
			{
				swap = temp[i];
				temp[i] = temp[j];
				temp[j] = swap;
			}
			j++;
		}
		i++;
	}
	return (temp);
}

void	sort_to_a(t_node **stack_a, t_node **stack_b)
{
	int	ind;

	while (lstsize(*stack_b) >= 1)
	{
		ind = find_max(*stack_b);
		if (ind > lstsize(*stack_b) / 2)
		{
			ind = lstsize(*stack_b) - ind;
			while (ind-- > 0)
				rra_rrb(stack_b, 'b');
		}
		else
		{
			while (ind-- > 0)
				ra_rb(stack_b, 'b');
		}
		pa_pb(stack_b, stack_a, 'a');
	}
	return ;
}
