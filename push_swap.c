/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:38:00 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/31 13:26:54 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_sort	data;

	if (argc > 1)
	{
		data.err_flag = 0;
		data.is_malloc = 0;
		if (argc == 2)
		{
			data.is_malloc = 1;
			data.str_nums = ft_split(argv[1], ' ');
			data.err_flag = check_nums(data.str_nums);
		}
		else
			data.err_flag = check_nums(argv + 1);
		check_err_flag(&data);
		fill_a_stack(&data);
		print_sort_commands(&data);
		return (0);
	}
	return (0);
}
