/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:30:42 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/07 15:35:14 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	check_duplicated_nums(char **arr)
{
	int	i;
	int	y;

	i = 0;
	while (arr[i] != NULL)
	{
		y = i + 1;
		while (arr[y] != NULL)
		{
			if (ft_strcmp(arr[i], arr[y]) == 0)
				return (1);
			y++;
		}
		i++;
	}
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
	if (check_duplicated_nums(arr) == 1)
		return (1);
	return (0);
}
