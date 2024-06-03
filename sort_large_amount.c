/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_amount.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:56:22 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/03 18:25:48 by sganiev          ###   ########.fr       */
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

void	sort_large_amount(t_sort *data)
{
	t_list	*current_a;
	t_list	*cheapest;
	t_list	*max_b;

	push_top_two(data);
	steps_initialize(data);
	current_a = data->a_stack;
	while (current_a)
	{
		if ((current_a->index + 1) <= data->num_count / 2)
			current_a->steps_count += current_a->index;
		else
			current_a->steps_count += (data->num_count - current_a->index);
		current_a = current_a->next;
	}
}
