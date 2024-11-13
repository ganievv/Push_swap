/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:16:39 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/03 18:20:34 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*find_min(t_list *stack)
{
	t_list	*min;

	if (stack == NULL)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->num < min->num)
			min = stack;
		stack = stack->next;
	}
	return (min);
}
