/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:39:08 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/03 15:39:22 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(t_list **stack)
{
	int	i;

	i = 0;
	while (*stack)
	{
		(*stack)->index = i;
		*stack = (*stack)->next;
		i++;
	}
}