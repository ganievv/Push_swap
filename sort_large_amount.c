/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_amount.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:56:22 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/04 18:08:43 by sganiev          ###   ########.fr       */
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
	if (data->num_count_a > 3)
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
	if (nbr > max_b->num || nbr < min_b->num)
		return (max_b->index);
	while (1)
	{
		if (current_b->next == NULL)
			next_b = data->b_stack;
		else
			next_b = current_b->next;
		if ((current_b->num > nbr) && (next_b->num < nbr))
			return (next_b->index);
		current_b = next_b;
		if (current_b->num == min_b->num)
			return (-1);
	}
}

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
