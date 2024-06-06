/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:38:00 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/01 13:59:16 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return (0) or return (1) when there is no parameters ???

static int	is_str_empty(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_sort	data;

	if (argc == 1 || (argc == 2 && (is_str_empty(argv[1]) == 1)))
		return (0);
	data.err_flag = 0;
	data.is_malloc = 0;
	if (argc == 2)
	{
		data.is_malloc = 1;
		data.str_nums = ft_split(argv[1], ' ');
		data.err_flag = check_nums(data.str_nums);
	}
	else
	{
		data.str_nums = argv + 1;
		data.err_flag = check_nums(data.str_nums);
	}
	check_err_flag(&data);
	fill_a_stack(&data);
	print_sort_commands(&data);
	return (0);
}
