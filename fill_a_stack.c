/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:05:44 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/31 17:34:42 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// you should check here for duplicated numbers

static t_list	*find_last_node(t_list *head)
{
	t_list	*last;

	while (head)
	{
		last = head;
		head = head->next;
	}
	return (last);
}

static void	append_node(int num, t_sort *data)
{
	t_list			*new_node;
	t_list			*last;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->num = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (data->a_stack == NULL)
		data->a_stack = new_node;
	else
	{
		last = find_last_node(data->a_stack);
		last->next = new_node;
		new_node->prev = last;
	}
}

void	fill_a_stack(t_sort *data)
{
	int	i;

	i = 0;
	data->a_stack = NULL;
	while (data->str_nums[i])
	{
		append_node(ft_atoi(data->str_nums[i]), data);
		i++;
	}
	if (data->is_malloc == 1)
		clean_arr_ptrs(data);
}
