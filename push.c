/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:38:17 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/31 21:27:32 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_dst, t_list **stack_src)
{
	t_list	*tmp;

	if (stack_src && *stack_src)
	{
		tmp = (*stack_src)->next;
		if (*stack_dst == NULL)
		{
			*stack_dst = *stack_src;
			(*stack_dst)->next = NULL;
		}
		else
		{
			(*stack_dst)->prev = *stack_src;
			(*stack_src)->next = *stack_dst;
			(*stack_dst) = *stack_src;
		}
		*stack_src = tmp;
		if (*stack_src)
			(*stack_src)->prev = NULL;
	}
}
