/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_hint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:53:00 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 22:25:33 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deal_hint(t_hint hint)
{
	int	i;
	int	j;
	int	len;

	len = ft_lstcount(hint.lst_lim);
	j = 0;
	while (j < len - 1)
	{
		i = 0;
		while (i < ((t_pile*)(hint.lst_lim->content))->val)
			sort_hint(&hint, &i, j);
		hint.lst_lim = hint.lst_lim->next;
		j++;
	}
	i = 0;
	while (i < ((t_pile*)(hint.lst_lim->content))->val)
		sort_hint_2(&hint, &i);
}
