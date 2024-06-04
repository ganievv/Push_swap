/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_push_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:50:03 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/04 22:36:43 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*num_search(t_sort *data, int nbr)
{
	t_list	*current_a;

	current_a = data->a_stack;
	while (current_a)
	{
		if (current_a->num == nbr)
			break ;
		current_a = current_a->next;
	}
	return (current_a);
}

static void	rest_rotate_a(t_list **stack, int *rotate_a, int rotate_a_dir)
{
	while (*rotate_a > 0)
	{
		if (rotate_a_dir == 1)
		{
			rotate_norm(stack);
			rotate_norm(stack);
			write (1, "ra\n", 3);
		}
		else
		{
			rotate_reverse(stack);
			rotate_reverse(stack);
			write (1, "rra\n", 3);
		}
		(*rotate_a)--;
	}
}

static void	rest_rotate_b(t_list **stack, int *rotate_a, int rotate_a_dir)
{
	while (*rotate_a > 0)
	{
		if (rotate_a_dir == 1)
		{
			rotate_norm(stack);
			rotate_norm(stack);
			write (1, "rb\n", 3);
		}
		else
		{
			rotate_reverse(stack);
			rotate_reverse(stack);
			write (1, "rrb\n", 3);
		}
		(*rotate_a)--;
	}
}

// in rotate_norm() function you should delete printing of 'ra'
// (maybe also the same thing in reverse)

void	make_push_op(t_sort *data, int nbr)
{
	t_list	*current_a;

	current_a = num_search(data, nbr);
	if (current_a->inf.rotate_a_dir == current_a->inf.rotate_b_dir)
	{
		while (current_a->inf.rotate_a > 0 && current_a->inf.rotate_b > 0)
		{
			if (current_a->inf.rotate_a_dir == 1)
			{
				rotate_norm(&(data->a_stack));
				rotate_norm(&(data->b_stack));
				write (1, "rr\n", 3);
			}
			else
			{
				rotate_reverse(&(data->a_stack));
				rotate_reverse(&(data->b_stack));
				write (1, "rrr\n", 3);
			}
			current_a->inf.rotate_a--;
			current_a->inf.rotate_b--;
		}
	}
	rest_rotate_a(&(data->a_stack), &(current_a->inf.rotate_a),
		current_a->inf.rotate_a_dir);
	rest_rotate_b(&(data->b_stack), &(current_a->inf.rotate_b),
		current_a->inf.rotate_b_dir);
}
