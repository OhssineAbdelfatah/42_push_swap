#include"push_swap.h"

void throw_error(char *str)
{
    ft_printf("%s\n",str);
    exit(0);
}

static size_t	count_size(int nbr)
{
	size_t	len;

	len = 0;
	if (nbr < 1)
	{
		len++;
		nbr = nbr * -1;
	}
	while (nbr)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*nbr;
	size_t	last;

	last = 0;
	len = count_size(n);
	nbr = (char *)malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	if (n < 0)
	{
		nbr[0] = '-';
		n = n * -1;
		last = 1;
	}
	while (len-- > last)
	{
		if (n < 0)
			nbr[len] = ((n % 10) * (-1) + 48);
		else
			nbr[len] = ((n % 10) + 48);
		n = n / 10;
	}
	return (nbr);
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


