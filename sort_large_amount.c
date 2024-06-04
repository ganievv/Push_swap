/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_amount.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:56:22 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/04 14:59:14 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	steps_initialize(t_sort *data)
{
	t_list	*current;

	current = data->a_stack;
	while (current)
	{
		current->steps_count = 0;
		current = current->next;
	}
}

static void	push_top_two(t_sort *data)
{
	push(&(data->b_stack), &(data->a_stack));
	write (1, "pb\n", 3);
	if (data->num_count > 3)
	{
		push(&(data->b_stack), &(data->a_stack));
		write (1, "pb\n", 3);
	}
}

// this "(data->num_count > 3)" should be in other loop above
// while (current_a). Because after finding the best number to push
// you should push it and then "data->num_count--" and than start from the first
// node again for finding the best node to push

//max_b = find_max(data->b_stack);
//if (current_a->num > max_b->num)
//{
//	if (max_b->index != 0)
//		current_a->steps_count++;
//}

// are you changing b_stack when you connect end node with start ?

static int	find_insert_position_b(t_sort *data, int nbr)
{
	t_list	*current_b;
	t_list	*max_b;
	t_list	*min_b;
	t_list	*next_b;

	max_b = find_max(data->b_stack);
	min_b = find_min(data->b_stack);
	current_b = max_b;
	while (1)
	{
		if (current_b->next == NULL)
			next_b = data->b_stack;
		else
			next_b = current_b->next;
		if ((current_b->num > nbr)
			&& (next_b->num < nbr))
		{
			return (next_b->index);
		}
		current_b = next_b;
		if (current_b->num == min_b->num)
			return (-1);
	}
}

static void	choose_push_num(t_sort *data)
{
	t_list	*current_a;
	t_list	*current_b;
	int		rotate_a;
	int		rotate_b;

	rotate_a = 0;
	rotate_b = 0;
	current_a = data->a_stack;
	current_b = data->b_stack;
	while (current_a)
	{
		if ((current_a->index + 1) <= data->num_count / 2)
			rotate_a += current_a->index;
		else
			rotate_a += (data->num_count - current_a->index);
		current_a = current_a->next;
	}
}

void	sort_large_amount(t_sort *data)
{
	t_list	*current_a;

	push_top_two(data);
	steps_initialize(data);
	current_a = data->a_stack;
	while (data->num_count > 3)
	{
		choose_push_num(data);
		data->num_count--;
	}
}
