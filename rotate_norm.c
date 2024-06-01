/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:31:30 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/01 13:00:50 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_norm(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (stack && *stack && (*stack)->next)
	{
		last = find_last_node(*stack);
		first = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last->next = first;
		last->next->next = NULL;
		last->next->prev = last;
	}
}