/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:40:55 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 22:40:59 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	end_push(t_list **lst_a, t_list **lst_b)
{
	while (*lst_b)
	{
		push(lst_b, lst_a);
		ft_putendl("pa");
	}
}
