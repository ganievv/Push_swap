/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:15:26 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/03 15:54:25 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack, int num_count)
{
	int	tmp;

	if (num_count > 1 && stack && stack->next)
	{
		tmp = stack->num;
		stack->num = stack->next->num;
		stack->next->num = tmp;
		put_index(stack);
		write (1, "sa\n", 3);
	}
}
