/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:21:46 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/24 13:34:56 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *heap)
{
	int	temp;
	int	i;

	if (heap->size_a > 1)
	{
		temp = heap->stack_a[heap->size_a - 1];
		i = heap->size_a - 1;
		while (i > 0)
		{
			heap->stack_a[i] = heap->stack_a[i - 1];
			i--;
		}
		heap->stack_a[i] = temp;
	}
	write(1, "rra\n", 4);
}

int	*push_down(int *arr, int size)
{
	int	i;

	i = size - 1;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	return (arr);
}

int	*push_up(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	return (arr);
}

void	bubble_sort(t_stack *heap)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < heap->size_a - 1)
	{
		if (heap->sorted_stack[i] > heap->sorted_stack[i + 1])
		{
			tmp = heap->sorted_stack[i];
			heap->sorted_stack[i] = heap->sorted_stack[i + 1];
			heap->sorted_stack[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	is_it_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		i++;
	else if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
