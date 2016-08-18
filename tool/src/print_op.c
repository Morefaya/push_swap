/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 17:24:49 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/17 17:24:51 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tool.h"

void	print_op(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_putendl(((t_op*)(lst->content))->op);
		lst = lst->next;
	}
}
