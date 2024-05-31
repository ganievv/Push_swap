/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:30:42 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/31 13:43:59 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_nums(char **arr)
{
	int	err_flag;
	int	i;

	i = 0;
	err_flag = 0;
	while (arr[i])
	{
		err_flag = check_str(arr[i]);
		if (err_flag == 1)
			return (1);
		i++;
	}
}
