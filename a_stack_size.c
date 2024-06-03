/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:25:59 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/03 16:26:02 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_stack_size(t_sort *data)
{
	t_list	*current;

	current = data->a_stack;
	while (current)
	{
		data->num_count++;
		current = current->next;
	}
}
