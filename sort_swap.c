/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:53:50 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/24 19:01:22 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(int *arr, int size)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = arr[0];
	while (i < size)
	{
		if (arr[i] < smallest)
			smallest = arr[i];
		i++;
	}
	return (smallest);
}

void	smart_rotate_a(t_stack *heap)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = find_smallest(heap->stack_a, heap->size_a);
	while (heap->stack_a[i] != smallest)
		i++;
	if (i <= heap->size_a / 2)
	{
		while (heap->stack_a[0] != smallest)
			ra(heap);
	}
	else
	{
		while (heap->stack_a[0] != smallest)
			rra(heap);
	}
}

void	sort_swap(t_stack *heap)
{
	while (heap->size_a > 3)
	{
		if (heap->stack_a[0] == find_smallest(heap->stack_a, heap->size_a))
			pb(heap);
		else
			smart_rotate_a(heap);
	}
	sort_three(heap);
	while (heap->size_b > 0)
		pa(heap);
}
