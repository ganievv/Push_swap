/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_amount.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:56:22 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/03 15:41:15 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large_amount(t_sort *data)
{
	t_list	*current_a;
	t_list	*cheapest;

	push(&(data->b_stack), &(data->a_stack));
	put_index(&(data->a_stack));
	write (1, "pb\n", 3);
	data->num_count--;
	if (data->num_count > 3)
	{
		push(&(data->b_stack), &(data->a_stack));
		put_index(&(data->a_stack));
		write (1, "pb\n", 3);
	}
	current_a = data->a_stack;
	while (current_a && (data->num_count > 3))
	{
		data->num_count--;
		current_a = current_a->next;
	}
}
