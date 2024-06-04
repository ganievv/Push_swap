/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_top_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:15:11 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/04 18:15:35 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top_two(t_sort *data)
{
	push(&(data->b_stack), &(data->a_stack));
	write (1, "pb\n", 3);
	if (data->num_count_a > 3)
	{
		push(&(data->b_stack), &(data->a_stack));
		write (1, "pb\n", 3);
	}
}
