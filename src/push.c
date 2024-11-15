/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:38:17 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/06 15:55:31 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_list **stack_dst, t_list **stack_src, int *dst_s, int *src_s)
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
		put_index(*stack_dst);
		put_index(*stack_src);
		stack_size(*stack_dst, dst_s);
		stack_size(*stack_src, src_s);
	}
}
