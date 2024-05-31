/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:43:06 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/31 17:50:52 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_sort
{
	char	**str_nums;
	int		is_malloc;
	int		err_flag;
	t_list	*a_stack;
	t_list	*b_stack;
}	t_sort;

long	ft_atol(char *str);
int		check_nums(char **arr);
void	check_err_flag(t_sort *data);
void	clean_arr_ptrs(t_sort *data);
void	fill_a_stack(t_sort *data);
void	print_sort_commands(t_sort *data);

#endif