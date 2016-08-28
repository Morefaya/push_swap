/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:43:49 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/20 19:33:34 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	**tab_op;
	t_mark	mark;
	t_list	*op_a;
	t_list	*op_b;
	t_list	*op;

	lst_a = NULL;
	lst_b = NULL;
	op_a = NULL;
	op_b = NULL;
	op = NULL;
	if (!(lst_a = lst_tab2d(ac, av)))
		return (1);
	if (!(tab_op = init_op()))
		return (2);
	print_lst(lst_a);
	ft_putchar('\n');
	quick_sort(&lst_a, &lst_b);

	print_lst(lst_a);
	print_lst(lst_b);
	ft_putchar('\n');

	mark.tab_op = tab_op;
	mark.op_lst = &op_a;
	jc_sort(&lst_a, 1, &mark);
	mark.op_lst = &op_b;
	jc_sort(&lst_b, 0, &mark);

	/*print_lst(lst_a);
	print_lst(lst_b);
	ft_putchar('\n');*/

	print_op(op_a);
	ft_putchar('\n');
	print_op(op_b);
	ft_putchar('\n');

	check_op(&op_a);
	check_op(&op_b);
	
	print_op(op_a);
	ft_putchar('\n');
	print_op(op_b);
	ft_putchar('\n');

	fusion_sort(&op, op_a, op_b, tab_op);

	/*print_op(op);
	ft_putchar('\n');*/

	/*print_lst(lst_a);
	print_lst(lst_b);
	ft_putchar('\n');*/
	range_sort_asc(&lst_a);
	range_sort_dsc(&lst_b);
	turn_list(&lst_a);
	turn_list(&lst_b);
	while (lst_b)
		push(&lst_b, &lst_a);
	/*print_lst(lst_a);
	print_lst(lst_b);*/
	ft_lstdel(&lst_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(&lst_b, (void(*)(void*, size_t))del_content);
	free_init(tab_op);
	ft_lstdel(&op_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(&op_b, (void(*)(void*, size_t))del_content);
	ft_lstdel(&op, (void(*)(void*, size_t))del_content);
	return (0);
}
