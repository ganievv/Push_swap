/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_arr_ptrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:37:40 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/31 14:41:08 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_arr_ptrs(t_sort *data)
{
	int	i;

	i = 0;
	while (data->str_nums[i])
	{
		free(data->str_nums[i]);
		data->str_nums[i] = NULL;
		i++;
	}
	if (data->str_nums)
		free(data->str_nums);
	data->str_nums = NULL;
}
