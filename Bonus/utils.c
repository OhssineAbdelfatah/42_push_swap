/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:33:58 by aohssine          #+#    #+#             */
/*   Updated: 2024/06/02 12:51:11 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	execute_rule(t_node **stack_a, t_node **stack_b)
{
	char	buffer[1000];
	int		r_read;
	char	c;
	int		i;

	i = 0;
	r_read = read(0, &c, 1);
	while (r_read)
	{
		if (i == 999)
			return (-1);
		buffer[i++] = c;
		if (buffer[0] == '\n')
			return (-1);
		if (c == '\n')
		{
			buffer[--i] = '\0';
			if (check_exec_rule(buffer, i, stack_a, stack_b) == -1)
				return (-1);
			i = 0;
		}
		r_read = read(0, &c, 1);
	}
	return (0);
}
