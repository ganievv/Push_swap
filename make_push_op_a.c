/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_push_op_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:47:27 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/07 15:29:23 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	find_insert_position_a(t_sort *data, int nbr)
{
	t_list	*current_a;
	t_list	*max_a;
	t_list	*min_a;
	t_list	*next_a;

	max_a = find_max(data->a_stack);
	min_a = find_min(data->a_stack);
	current_a = min_a;
	if (nbr > max_a->num || nbr < min_a->num)
		return (min_a->index);
	while (1)
	{
		if (current_a->next == NULL)
			next_a = data->a_stack;
		else
			next_a = current_a->next;
		if ((current_a->num < nbr) && (next_a->num > nbr))
			return (next_a->index);
		current_a = next_a;
		if (current_a->num == max_a->num)
			return (-1);
	}
}

static void	rotate_a(t_list **stack, int *rotate_a, int rotate_a_dir)
{
	while ((*rotate_a) > 0)
	{
		if (rotate_a_dir == 1)
		{
			rotate_norm(stack);
			write (1, "ra\n", 3);
		}
		else
		{
			rotate_reverse(stack);
			write (1, "rra\n", 4);
		}
		(*rotate_a)--;
	}
}

static void	move_min_up(t_sort *data)
{
	t_list	*min_a;

	min_a = find_min(data->a_stack);
	if (min_a->index != 0)
	{
		calc_rotations(&(min_a->inf.rotate_a),
			&(min_a->inf.rotate_a_dir),
			min_a->index, data->num_count_a);
		rotate_a(&(data->a_stack), &(min_a->inf.rotate_a),
			min_a->inf.rotate_a_dir);
	}
}

void	make_push_op_a(t_sort *data)
{
	t_list	*current_b;
	int		a_index;

	while (data->num_count_b > 0)
	{
		current_b = data->b_stack;
		a_index = find_insert_position_a(data, current_b->num);
		calc_rotations(&(current_b->inf.rotate_a),
			&(current_b->inf.rotate_a_dir),
			a_index, data->num_count_a);
		rotate_a(&(data->a_stack), &(current_b->inf.rotate_a),
			current_b->inf.rotate_a_dir);
		push(&(data->a_stack), &(data->b_stack),
			&(data->num_count_a), &(data->num_count_b));
		write (1, "pa\n", 3);
	}
	move_min_up(data);
}
