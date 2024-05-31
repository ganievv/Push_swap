/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:31:30 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/31 21:40:17 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_norm(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	int		buf;

	first = *stack;
	last = find_last_node(first);
	buf = last->num;
	last->num = first->num;
	first->num = buf;
}
