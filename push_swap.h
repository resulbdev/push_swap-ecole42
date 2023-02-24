/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:54:05 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/24 19:01:54 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	*sorted_stack;
	int	*index;
	int	maxbit;
	int	size_a;
	int	size_b;
	int	size;
}		t_stack;

void	sa(t_stack *heap);
void	pa(t_stack *heap);
void	pb(t_stack *heap);
void	ra(t_stack *heap);
void	rra(t_stack *heap);
void	sort_two(t_stack *heap);
void	sort_three(t_stack *heap);
void	sort_swap(t_stack *heap);
void	check_duplicate(int *stack_a, int numberlen, t_stack *heap);
int		is_sorted(int *stack_a, int numberlen);
int		is_it_number(char *str);
void	sorted_list(t_stack *heap);
int		num_all(char **arg, t_stack *heap);
int		numall2(char **str, int j, t_stack *heap);
void	ft_max_int_check(char *str, t_stack *heap);
void	bubble_sort(t_stack *heap);
int		*push_down(int *arr, int size);
int		*push_up(int *arr, int size);
void	find_maxbit(t_stack *data);
int		find_index(t_stack *data, int nbr);
void	radix(t_stack *heap);
void	all_free(t_stack *heap);

#endif
