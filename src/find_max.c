/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:04:23 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/03 16:13:04 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*find_max(t_list *stack)
{
	t_list	*max;

	if (stack == NULL)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (max->num < stack->num)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
