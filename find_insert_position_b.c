/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_insert_position_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:10:57 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/04 18:12:34 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//max_b = find_max(data->b_stack);
//if (current_a->num > max_b->num)
//{
//	if (max_b->index != 0)
//		current_a->steps_count++;
//}

// are you changing b_stack when you connect end node with start ?

int	find_insert_position_b(t_sort *data, int nbr)
{
	t_list	*current_b;
	t_list	*max_b;
	t_list	*min_b;
	t_list	*next_b;

	max_b = find_max(data->b_stack);
	min_b = find_min(data->b_stack);
	current_b = max_b;
	if (nbr > max_b->num || nbr < min_b->num)
		return (max_b->index);
	while (1)
	{
		if (current_b->next == NULL)
			next_b = data->b_stack;
		else
			next_b = current_b->next;
		if ((current_b->num > nbr) && (next_b->num < nbr))
			return (next_b->index);
		current_b = next_b;
		if (current_b->num == min_b->num)
			return (-1);
	}
}