/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:33:44 by aohssine          #+#    #+#             */
/*   Updated: 2024/06/02 09:33:45 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_double(t_node *head)
{
	t_node	*tmp;
	t_node	*tmp1;

	tmp = head;
	while (tmp->next != NULL)
	{
		tmp1 = tmp->next;
		while (tmp1 != NULL)
		{
			if (tmp1->data == tmp->data)
			{
				free_stack(&head);
				return (-1);
			}
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	is_space(char c)
{
	if (c == ' ' || (c >= 13 && c <= 9))
		return (1);
	else
		return (0);
}

int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}

char	is_sign_doubled(char a, char b)
{
	if ((a == '-' && b == '-') || (a == '+' && b == '+'))
		return (1);
	else
		return (0);
}
