/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:18:56 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/06 15:47:56 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_size(t_list *stack, int *size)
{
	(*size) = 0;
	while (stack)
	{
		(*size)++;
		stack = stack->next;
	}
}
