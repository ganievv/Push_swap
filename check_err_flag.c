/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:24:49 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/31 14:29:43 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_err_flag(t_sort *data)
{
	if (data->err_flag == 1)
	{
		if (data->is_malloc == 1)
			clean_arr_ptrs(data->str_nums);
		ft_printf("Error\n");
		exit(1);
	}
}
