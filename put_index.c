/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:39:08 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/03 15:49:45 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(t_list **stack)
{
	t_list	*current;
	int		i;

	if (stack && *stack)
	{
		i = 0;
		current = *stack;
		while (current)
		{
			current->index = i;
			current = current->next;
			i++;
		}
	}
}
