/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:46:57 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/30 19:48:03 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_message(char *str, int fd)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
		write(fd, &str[i++], 1);
	return ;
}

int	lstsize(t_node *lst)
{
	t_node	*temp;
	int		i;

	if (lst == NULL)
		return (0);
	i = 0;
	temp = lst;
	while ((temp)->next != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (++i);
}

t_node	*creat_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
	{
		put_message("Error\n", 2);
		return (NULL);
	}
	node->data = num;
	node->next = NULL;
	node->ind = 0;
	return (node);
}
