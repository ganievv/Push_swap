/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:43:06 by sganiev           #+#    #+#             */
/*   Updated: 2024/06/06 17:48:07 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_rotate_dir
{
	int	rotate_a;
	int	rotate_a_dir;
	int	rotate_b;
	int	rotate_b_dir;
}	t_rotate_num;

typedef struct s_list
{
	int				num;
	int				index;
	int				steps_count;
	t_rotate_num	inf;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_sort
{
	char	**str_nums;
	int		is_malloc;
	int		err_flag;
	int		num_count_a;
	int		num_count_b;
	t_list	*a_stack;
	t_list	*b_stack;
}	t_sort;

long	ft_atol(char *str);
int		check_nums(char **arr);
void	check_err_flag(t_sort *data);
void	clean_arr_ptrs(t_sort *data);
void	fill_a_stack(t_sort *data);
void	print_sort_commands(t_sort *data);
t_list	*find_last_node(t_list *head);
void	swap(t_list *stack, int num_count);
void	push(t_list **stack_dst, t_list **stack_src, int *dst_s, int *src_s);
void	rotate_norm(t_list **stack);
void	rotate_reverse(t_list **stack);
void	sort_less_three(t_sort *data);
void	free_lists(t_sort *data);
void	sort_large_amount(t_sort *data);
int		is_sorted(t_list *stack);
void	put_index(t_list *stack);
void	stack_size(t_list *stack, int *size);
t_list	*find_min(t_list *stack);
t_list	*find_max(t_list *stack);
int		find_insert_position_b(t_sort *data, int nbr);
void	push_top_two(t_sort *data);
void	make_push_op_b(t_sort *data, int num);
void	make_push_op_a(t_sort *data);

#endif