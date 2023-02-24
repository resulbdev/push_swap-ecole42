/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:21:27 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/24 15:55:07 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(int *stack_a, int numberlen, t_stack *heap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < numberlen)
	{
		j = i + 1;
		while (j < numberlen)
		{
			if (stack_a[i] == stack_a[j])
			{
				write(2, "Error\n", 6);
				all_free(heap);
			}
			j++;
		}
		i++;
	}
}

int	num_all(char **arg, t_stack *heap)
{
	int		i;
	int		j;
	int		count;
	char	**str;

	i = 1;
	count = 0;
	j = 0;
	while (arg[i])
	{
		j = 0;
		str = ft_split(arg[i], ' ');
		count += numall2(str, j, heap);
		if (str[0] == NULL)
			return (0);
		i++;
		free(str);
	}
	return (count);
}

int	numall2(char **str, int j, t_stack *heap)
{
	int	count;

	count = 0;
	while (str[j])
	{
		if (!is_it_number(str[j]))
		{
			write(2, "Error\n", 6);
			free(heap);
			exit(0);
		}
		count++;
		free(str[j]);
		j++;
	}
	return (count);
}

void	ft_max_int_check(char *str, t_stack *heap)
{
	long	n;

	n = ft_atoi(str);
	if (n < -2147483648 || n > 2147483647)
	{
		write(2, "Error\n", 6);
		all_free(heap);
	}
}

int	is_sorted(int *stack_a, int numberlen)
{
	int	i;

	i = 0;
	while (i < numberlen - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
