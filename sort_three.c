/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:53:56 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/02 16:06:11 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	funcs1(t_stack *heap)
{
	if (heap->stack_a[0] > heap->stack_a[1]
		&& heap->stack_a[1] < heap->stack_a[2]
		&& heap->stack_a[0] < heap->stack_a[2])
	{
		sa(heap);
		return ;
	}
	if (heap->stack_a[0] > heap->stack_a[1]
		&& heap->stack_a[1] > heap->stack_a[2]
		&& heap->stack_a[0] > heap->stack_a[2])
	{
		ra(heap);
		sa(heap);
		return ;
	}
	if (heap->stack_a[0] > heap->stack_a[1]
		&& heap->stack_a[1] < heap->stack_a[2]
		&& heap->stack_a[0] > heap->stack_a[2])
	{
		ra(heap);
		return ;
	}
}

void	sort_three(t_stack *heap)
{
	funcs1(heap);
	if (heap->stack_a[0] < heap->stack_a[1]
		&& heap->stack_a[1] > heap->stack_a[2]
		&& heap->stack_a[0] < heap->stack_a[2])
	{
		sa(heap);
		ra(heap);
		return ;
	}
	if (heap->stack_a[0] < heap->stack_a[1]
		&& heap->stack_a[1] > heap->stack_a[2]
		&& heap->stack_a[0] > heap->stack_a[2])
	{
		rra(heap);
		return ;
	}
}
