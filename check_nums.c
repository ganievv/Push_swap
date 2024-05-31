/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:30:42 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/31 14:18:13 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_str(char *str)
{
	int		i;
	long	num;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (1);
	return (0);
}

int	check_nums(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (check_str(arr[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
