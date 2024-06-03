/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sort_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:50:12 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/03 15:38:53 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	num_counter(t_sort *data)
{
	t_list	*current;

	current = data->a_stack;
	while (current)
	{
		data->num_count++;
		current = current->next;
	}
}

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
	data->num_count = 0;
	num_counter(data);
	put_index(&(data->a_stack));
	if (is_sorted(data) == 0)
	{
		if (data->num_count < 4)
			sort_less_three(data);
		else if (data->num_count > 3)
			sort_large_amount(data);
	}
	print_a_stack(data->a_stack);
	free_lists(data);
}
