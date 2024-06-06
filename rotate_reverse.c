/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:42:54 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/06 15:39:02 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (stack && *stack && (*stack)->next)
	{
		last = find_last_node(*stack);
		first = *stack;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;
		*stack = last;
		put_index(*stack);
	}
}
