/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:43:37 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/04 15:17:30 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	two_num(t_sort *data)
{
	t_list	*current;

	current = data->a_stack;
	if (current->num > current->next->num)
		swap(data->a_stack, data->num_count_a);
}

static	void	three_num(t_sort *data)
{
	t_list	*current;

	current = data->a_stack;
	if ((current->num > current->next->num)
		&& (current->num > current->next->next->num))
		rotate_norm(&(data->a_stack));
	else if ((current->next->num > current->num)
		&& (current->next->num > current->next->next->num))
		rotate_reverse(&(data->a_stack));
	current = data->a_stack;
	if (current->num > current->next->num)
		swap(data->a_stack, data->num_count_a);
}

void	sort_less_three(t_sort *data)
{
	t_list	*current;

	current = data->a_stack;
	if (data->num_count_a == 2)
		two_num(data);
	else if (data->num_count_a == 3)
		three_num(data);
}
