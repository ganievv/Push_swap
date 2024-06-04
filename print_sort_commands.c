/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sort_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:50:12 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/04 15:16:34 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_a_stack(t_list *stack)
{
	ft_printf("a_stack: ");
	while (stack)
	{
		ft_printf("%d ", stack->num);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	print_sort_commands(t_sort *data)
{
	a_stack_size(data);
	put_index(&(data->a_stack));
	if (is_sorted(data) == 0)
	{
		if (data->num_count_a < 4)
			sort_less_three(data);
		else if (data->num_count_a > 3)
			sort_large_amount(data);
	}
	print_a_stack(data->a_stack);
	free_lists(data);
}
