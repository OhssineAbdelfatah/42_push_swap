/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:29:37 by aohssine          #+#    #+#             */
/*   Updated: 2024/06/02 12:06:08 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mini_check(char **argv, int i, int j)
{
	if (is_sign_doubled(argv[i][j], argv[i][j + 1]) || (ft_isdigit(argv[i][j])
			&& is_sign(argv[i][j + 1])))
		return (-1);
	if (is_sign(argv[i][j]) && (is_sign(argv[i][j + 1]) || is_space(argv[i][j
				+ 1])))
		return (-1);
	if (!ft_isdigit(argv[i][j]) && !is_space(argv[i][j])
		&& !is_sign(argv[i][j]))
		return (-1);
	if (is_sign(argv[i][j]) && argv[i][j + 1] == '\0')
		return (-1);
	return (0);
}

int	check_args(int len, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (++i < len)
	{
		if (argv[i][0] == '\0')
			return (-1);
		j = -1;
		flag = 0;
		while (argv[i][++j])
		{
			if (mini_check(argv, i, j) == -1)
				return (-1);
			if (is_space(argv[i][j]))
				flag++;
		}
		if (flag == j)
			return (-1);
	}
	return (0);
}

t_node	*fill_args(char **argv)
{
	int		i;
	int		j;
	char	**arg;
	t_node	*n;

	n = NULL;
	i = 0;
	while (argv[++i])
	{
		arg = ft_split(argv[i], ' ');
		j = -1;
		while (arg[++j])
		{
			if (add_to_stack(creat_node(num(arg[j], arg, &n)), &n) == -1)
			{
				free_stack(&n);
				free_args(arg);
				return (NULL);
			}
		}
		free_args(arg);
	}
	if (check_double(n) == -1)
		return (NULL);
	return (n);
}

static int	space_sign(const char *s, int *sign)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == 32 || (s[i] < 14 && s[i] > 8)))
		i++;
	if (s[i] && (s[i] == '-' || s[i] == '+'))
	{
		if (s[i] == '-')
			*sign *= (-1);
		i++;
	}
	return (i);
}

int	num(const char *str, char **arg, t_node **head)
{
	int		i;
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	i = space_sign(str, &sign);
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + str[i] - 48;
		if ((res > INT32_MAX && sign == 1) || (res > 2147483648 && sign == -1))
		{
			free_args(arg);
			free_stack(head);
			put_message("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return ((int)res * sign);
}
