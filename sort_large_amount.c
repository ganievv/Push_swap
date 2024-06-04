/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_amount.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:56:22 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/04 18:16:03 by sganiev          ###   ########.fr       */
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

// this "(data->num_count > 3)" should be in other loop above
// while (current_a). Because after finding the best number to push
// you should push it and then "data->num_count--" and than start from the first
// node again for finding the best node to push

static int	choose_min_steps(t_sort *data)
{
	t_list	*current_a;
	int		min;

	current_a = data->a_stack;
	min = current_a->steps_count;
	while (current_a)
	{
		if (current_a->steps_count < min)
			min = current_a->steps_count;
		current_a = current_a->next;
	}
	current_a = data->a_stack;
	while (current_a)
	{
		if (current_a->steps_count == min)
			return (current_a->num);
		current_a = current_a->next;
	}
	return (1);
}

static int	choose_push_num(t_sort *data)
{
	t_list			*current_a;
	t_rotate_num	inf;

	current_a = data->a_stack;
	b_stack_size(data);
	while (current_a)
	{
		if ((current_a->index + 1) <= data->num_count_a / 2) // rotate norm
		{
			inf.rotate_a = current_a->index;
			inf.rotate_a_dir = 1;
		}
		else  // rotate reverse
		{
			inf.rotate_a = (data->num_count_a - current_a->index);
			inf.rotate_a_dir = -1;
		}
		inf.rotate_b = find_insert_position_b(data, current_a->num);
		if (inf.rotate_b + 1 <= data->num_count_b / 2)  // rotate norm
		{
			inf.rotate_b_dir = 1;
		}
		else   // rotate reverse
		{
			inf.rotate_b = (data->num_count_b - inf.rotate_b);
			inf.rotate_b_dir = -1;
		}
		if (inf.rotate_a_dir == inf.rotate_b_dir) // if rotating is the same direction
		{
			if (inf.rotate_a < inf.rotate_b)
			{
				current_a->steps_count = inf.rotate_a;
				current_a->steps_count += (inf.rotate_b - inf.rotate_a);
			}
			else
			{
				current_a->steps_count = inf.rotate_b;
				current_a->steps_count += (inf.rotate_a - inf.rotate_b);
			}
		}
		else
			current_a->steps_count = inf.rotate_a + inf.rotate_b;
		current_a->steps_count++; // push number to 'b'
		current_a = current_a->next;
	}
	return (choose_min_steps(data));
}

void	sort_large_amount(t_sort *data)
{
	t_list	*current_a;
	int		num;

	push_top_two(data);
	steps_initialize(data);
	current_a = data->a_stack;
	while (data->num_count_a > 3)
	{
		num = choose_push_num(data);
		make_push_op(data, num);
		data->num_count_a--;
	}
}
