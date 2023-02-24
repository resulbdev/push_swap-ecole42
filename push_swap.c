/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:54:08 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/25 13:02:15 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_num(t_stack *heap)
{
	if (heap->size_a == 2)
		sort_two(heap);
	if (heap->size_a == 3)
		sort_three(heap);
	if (heap->size_a == 4 || heap->size_a == 5)
		sort_swap(heap);
	if (heap->size_a >= 6)
	{
		find_maxbit(heap);
		radix(heap);
	}
}

void	fill_stack(t_stack *heap, char **arg)
{
	int		i;
	int		j;
	int		r;
	char	**str;

	i = 1;
	j = 0;
	r = 0;
	while (arg[i])
	{
		str = ft_split(arg[i], ' ');
		j = 0;
		while (str[j])
		{
			ft_max_int_check(str[j], heap);
			heap->stack_a[r] = ft_atoi(str[j]);
			free(str[j]);
			j++;
			r++;
		}
		free(str);
		i++;
	}
}

void	all_free(t_stack *heap)
{
	free(heap->stack_a);
	free(heap->stack_b);
	free(heap->sorted_stack);
	free(heap);
	exit(0);
}

int	main(int arc, char **arg)
{
	t_stack	*heap;

	if (arc == 1)
		exit(0);
	heap = (t_stack *)malloc(sizeof(t_stack));
	heap->size_a = num_all(arg, heap);
	heap->size_b = 0;
	heap->size = heap->size_a;
	if (heap->size_a == 0)
	{
		free(heap);
		exit(0);
	}
	heap->stack_a = (int *)malloc(sizeof(int) * heap->size_a);
	heap->sorted_stack = (int *)malloc(sizeof(int) * heap->size_a);
	heap->stack_b = (int *)malloc(sizeof(int) * heap->size_a);
	fill_stack(heap, arg);
	check_duplicate(heap->stack_a, heap->size_a, heap);
	if ((is_sorted(heap->stack_a, heap->size_a) == 1))
		all_free(heap);
	sorted_list(heap);
	bubble_sort(heap);
	check_num(heap);
	all_free(heap);
}
