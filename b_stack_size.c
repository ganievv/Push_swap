/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:18:56 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/04 15:19:46 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_stack_size(t_sort *data)
{
	t_list	*current;

	data->num_count_b = 0;
	current = data->b_stack;
	while (current)
	{
		data->num_count_b++;
		current = current->next;
	}
}
