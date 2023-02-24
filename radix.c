/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:54:02 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/02 14:24:48 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_maxbit(t_stack *heap)
{
	int	max;

	heap->maxbit = 0;
	max = heap->size_a - 1;
	while (max > 0)
	{
		heap->maxbit++;
		max /= 2;
	}
}

int	find_index(t_stack *heap, int nbr)
{
	int	i;

	i = 0;
	while (i < heap->size)
	{
		if (heap->sorted_stack[i] == nbr)
			return (i);
		i++;
	}
	return (0);
}

void	radix(t_stack *heap)
{
	int	i;
	int	x;
	int	alen;

	i = 0;
	alen = heap->size_a;
	while (i < heap->maxbit)
	{
		x = 0;
		while (x < alen)
		{
			if ((find_index(heap, heap->stack_a[0]) >> i & 1))
				ra(heap);
			else
				pb(heap);
			x++;
		}
		while (heap->size_b)
			pa(heap);
		i++;
	}
}
