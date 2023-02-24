/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:21:49 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/24 15:54:52 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *heap)
{
	int	temp;

	temp = heap->stack_a[0];
	heap->stack_a[0] = heap->stack_a[1];
	heap->stack_a[1] = temp;
	write(1, "sa\n", 3);
}

void	pa(t_stack *heap)
{
	if (heap->size_b > 0)
	{
		heap->size_a++;
		heap->stack_a = push_down(heap->stack_a, heap->size_a);
		heap->stack_a[0] = heap->stack_b[0];
		heap->size_b--;
		heap->stack_b = push_up(heap->stack_b, heap->size_b);
		write(1, "pa\n", 3);
	}
	else
		return ;
}

void	pb(t_stack *heap)
{
	if (heap->size_a > 0)
	{
		heap->size_b++;
		heap->stack_b = push_down(heap->stack_b, heap->size_b);
		heap->stack_b[0] = heap->stack_a[0];
		heap->size_a--;
		heap->stack_a = push_up(heap->stack_a, heap->size_a);
		write(1, "pb\n", 3);
	}
	else
		return ;
}

void	ra(t_stack *heap)
{
	int	temp;
	int	i;

	if (heap->size_a > 1)
	{
		temp = heap->stack_a[0];
		i = 0;
		while (i < heap->size_a - 1)
		{
			heap->stack_a[i] = heap->stack_a[i + 1];
			i++;
		}
		heap->stack_a[i] = temp;
	}
	write(1, "ra\n", 3);
}

void	sorted_list(t_stack *heap)
{
	int	i;

	i = 0;
	while (i < heap->size_a)
	{
		heap->sorted_stack[i] = heap->stack_a[i];
		i++;
	}
}
