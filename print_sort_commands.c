/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sort_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:50:12 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/31 19:10:49 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	num_counter(t_sort *data)
{
	t_list	*current;

	current = data->a_stack;
	while (current)
	{
		data->num_count++;
		current = current->next;
	}
}

void	print_sort_commands(t_sort *data)
{
	data->num_count = 0;
	num_counter(data);
}
