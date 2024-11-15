/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_amount.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:56:22 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/07 15:36:33 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

// if rotate direction is 1  -> rotate_norm()
// if rotate direction is -1 -> rotate_reverse()

static void	calc_rotations(int *rotate_num, int *rotate_dir, int index,
int stack_size)
{
	if (index == 0)
	{
		(*rotate_num) = index;
		(*rotate_dir) = 0;
		return ;
	}
	if ((index + 1) <= stack_size / 2)
	{
		(*rotate_num) = index;
		(*rotate_dir) = 1;
	}
	else
	{
		(*rotate_num) = (stack_size - index);
		(*rotate_dir) = -1;
	}
}

static void	rotation_plus(t_rotate_num *inf, int *steps_count)
{
	if (inf->rotate_a_dir == inf->rotate_b_dir)
	{
		if (inf->rotate_a < inf->rotate_b)
		{
			(*steps_count) = inf->rotate_a;
			(*steps_count) += (inf->rotate_b - inf->rotate_a);
		}
		else
		{
			(*steps_count) = inf->rotate_b;
			(*steps_count) += (inf->rotate_a - inf->rotate_b);
		}
	}
	else
		(*steps_count) = inf->rotate_a + inf->rotate_b;
	(*steps_count)++;
}

static int	choose_push_num(t_sort *data)
{
	t_list			*current_a;
	int				b_index;

	current_a = data->a_stack;
	stack_size(data->b_stack, &(data->num_count_b));
	while (current_a)
	{
		calc_rotations(&(current_a->inf.rotate_a),
			&(current_a->inf.rotate_a_dir),
			current_a->index, data->num_count_a);
		b_index = find_insert_position_b(data, current_a->num);
		calc_rotations(&(current_a->inf.rotate_b),
			&(current_a->inf.rotate_b_dir),
			b_index, data->num_count_b);
		rotation_plus(&(current_a->inf), &(current_a->steps_count));
		current_a = current_a->next;
	}
	return (choose_min_steps(data));
}

void	sort_large_amount(t_sort *data)
{
	t_list	*current_a;
	int		num;

	push_top_two(data);
	current_a = data->a_stack;
	while (current_a)
	{
		current_a->steps_count = 0;
		current_a = current_a->next;
	}
	while (data->num_count_a > 3)
	{
		num = choose_push_num(data);
		make_push_op_b(data, num);
	}
	sort_less_three(data);
	make_push_op_a(data);
}
